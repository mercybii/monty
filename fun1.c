#include "monty.h"
#include "commads.h"

/**
 * main - interprets a monty files
 *
 * @argc: argument counter
 * @argv: arguments
 * Return: Always 0.
 */


int main(int argc, char **argv)
{

file_open(argc, argv);

parse_line();

return (0);
}

/**
 * parse_line - reads and tokenizes line
 */

void parse_line(void)
{
stack_t *head = NULL;
char *buf = NULL, *buf2 = NULL, **commands;
size_t len = 0;
ssize_t nread;
int line_counter = 0, i = 0, buff_std = buffstd;
/*allocate memory to the new node*/
commands = malloc(buff_std * sizeof(char *));
if (commands == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
/* loop to read and procress each line from the input*/
for (line_counter = 1; (nread = getline(&buf, &len, command_t.store_check))
!= -1; line_counter++)
{
if (nread == 2)
continue;
/*the character to be tokenze*/
buf2 = strtok(buf, " \n\t$");
command_t.line = buf2;
if (buf2 == NULL || buf2[0] == '#')
continue;
validate_push_opcode(i, line_counter, commands, buf2, head);
command_t.number = commands[1];
command_t.instructions = commands;
call_opcode(line_counter, &head);
}
free_all(buf, head, commands, command_t.store_check);
}


/**
 * call_opcode - calls on struct function to find opcode and execute
 *
 * @line_counter: line number of opcode
 * @head: pointer to list
 */

void call_opcode(int line_counter, stack_t **head)
{
void (*f)(stack_t **stack, unsigned int line_number);

f = select_command(command_t.instructions);
if (f == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_counter,
command_t.instructions[0]);
free_all(command_t.line, *head, command_t.instructions,
command_t.store_check);
exit(EXIT_FAILURE);
}
f(head, line_counter);
}


/**
 * validate_push_opcode - validates if push has an argument
 *
 * @i: counter
 * @line_counter: command lin number
 * @commands: tokenized line
 * @buffer2: tokens iterator
 * @head: pointer to list
 */

void validate_push_opcode(int i, int line_counter, char **commands,
char *buf2, stack_t *head)
{
for (i = 0; buf2; i++)
{
commands[i] = buf2;
buf2 = strtok(NULL, " \n\t$");
if (strcmp(commands[i], "push") == 0)
{
if (i >= 2)
break;
if (buf2 == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_counter);
free_all(command_t.line, head, commands, command_t.store_check);
exit(EXIT_FAILURE);
}
}
}
}
