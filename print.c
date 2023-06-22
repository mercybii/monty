#include "monty.h"

/**
 * pint - it print the top element
 *
 * @stack: pointer to the list
 * @line_number: is the number of line where the comands are found
 */

void pint(stack_t **stack, unsigned int line_number)
{
	/*check if the elemant is empty*/
	if (!*stack || !stack)
	{

		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(command_t.instructions);
		free(command_t.line);
		fclose(command_t.store_check);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
