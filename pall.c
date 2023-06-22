#include "monty.h"


/**
 * pall - it prints the list
 *
 * @stack: is the pointer to the list
 * @line_number: is the command line found in the stack
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *tmp = *stack;
	(void)line_number;

	/*check if the stack is empty*/
	if (!stack)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
