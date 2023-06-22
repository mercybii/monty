#include "monty.h"

/**
 * add - add an element at the top
 *
 * @stack: pointing to the list
 * @line_number: number of line command
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	/* declaretion of variables */

	stack_t *tmp = *stack;

	stack_t *count = *stack;/*count the number of element */
	int i = 0;
/*count the number of element in the stack*/
	for (; count; i++)
		count = count->next;
	/*check if the stack is empty */
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		frees_struct(stack);
	}
	tmp->next->n = tmp->n + tmp->next->n;
	pop(stack, line_number);
}
