#include "monty.h"

/**
 * mul- multiply the element at the top
 *
 * @stack: is the point to the list
 * @line_number: is where the number of line is found
 */

void mul(stack_t **stack, unsigned int line_number)
{
	/*declaretion of variables*/
	stack_t *tmp = *stack;
	stack_t *count = *stack;
	int b = 0;

	/* count the element it stack*/

	for(; count; b++)
		count = count->next;
	/*check if tha stack is empty or less than 2*/
	if (b <2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: cant't mul, stack too short\n", line_number);
		frees_struct(stack);
	}
	tmp->next->n = tmp->n *tmp->next->n;

	pop(stack, line_number);
}
