#include "monty.h"

/**
 * file_open - it opens the bytecode file
 *
 * @argc: it is the agument at the center
 * @argv: it is the agument
 *
 * Return: the file point
 */

void file_open(int argc, char **argv)
{
FILE *check = NULL;

if (argc == 2)
{
/*open the file in the read mode*/
check = fopen(argv[1], "r");

if (check == NULL)
{
fprintf(stderr, "Error: cant'open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
command_t.store_check = check;

}
else
{
fprintf(stderr, "USAGE: monty file\n");
exit( EXIT_FAILURE);
}

}

/**
 * isdigit_str - check if a string contains all the element
 * @token: string
 *
 * Return: 0 when they is no numbers
 */

int isdigit_str(char *token)
{
int j = 0;

if (token == NULL)
return(0);

if (token[j] == '-')
j++;
while (token[j])
{
/*to check if the character is not a digit*/
if (isdigit(token[j]) == 0)
return (0);

j++;
}
return (1);
}


/**
 * frees_struct - frees elements
 *
 * @stacks: pointer to the list
 */

void frees_struct(stack_t **stack)
{
free(command_t.instructions);
free(command_t.line);
free_stack_t(stack);
fclose(command_t.store_check);
exit(EXIT_FAILURE);
}

/**
 * free_all - free the ement
 *
 * @line: getline buffer
 * @mercy: point to the list
 * @commands: pointer to the commands
 * @check: the file point
 */

void free_all(char *line, stack_t *mercy, char **commands, FILE *check)
{
	free(line);
	free_stack_t(&mercy);
	free(commands);
	fclose(check);
}

