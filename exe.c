#include "monty.h"

/**
 * parse_line - it tokenizes the line and also read
 *
 */

void parse_line(void)
{
	/*declaration */
	stack_t *mercy = NULL;
	char *buf = NULL, *buf2 = NULL, **commands;
	size_t len = 0;
	ssize_t nread;
	int line_count = 0, i = 0, buff_std = buffstd;

	/*alocation of memory*/
	commands = malloc(buff_std * sizeof(char *));
	if (commands == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (line_count = 1; (nread = getline(&buf, &len, command_t.store_check))
			!= -1; line_count++)
	{
		if (nread == 2)
			continue;
		buf2 = strtok(buf2, "\n\t$");
		command_t.line = buf;
		if (buf2 == NULL || buf2[0] =='#')
			continue;
		validate_push_opcode(i, line_count, commands, buf2, mercy);
		command_t.number = commands[1];
		command_t.instructions = commands;
		call_opcode(line_count, &mercy);
	}
	free_all(buf, mercy, commands, command_t.store_check);
}


/**
 * call_opcode - calls on struct function
 *
 * @line_count: line nummber of opcode
 * @mercy: pointer to the list
 */

void call_opcode(int line_count, stack_t **mercy)
{
	void(*f)(stack_t **stack, unsigned int line_number);
	f = select_command(command_t.instructions
);
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknow instruction %s\n", line_count,
				command_t.instructions[0]);
		free_all(command_t.line, *mercy, command_t.instructions,
				command_t.store_check);
		exit(EXIT_FAILURE);
	}
	f(mercy, line_count);
}


/**
 * validate_push_opcode - if they is an agument it validate
 *
 * @i: count
 * @line_count: command line number
 * @commands: line to tokenize
 * @buffer2: token iteretor
 * @mercy: point to list
 */

void validate_push_opcode(int i, int line_count, char **commands,
		char *buffer2, stack_t *mercy)
{
	for (i = 0; buffer2; i++)
	{
		/*token to store in the command line*/
		commands[i] = buffer2;
		buffer2 = strtok(NULL, "\n\t$");
		if (strcmp(commands[i], "push") == 0)
		{
			if (i >=2)/*it breakes if they is no token after*/
				break;
			if(buffer2 == NULL)
			{
				fprintf(stderr, "L%d: usage: push interger\n", line_count);
				free_all(command_t.line, mercy, commands, command_t.store_check);
				exit(EXIT_FAILURE);
			}
		}
	}
}

