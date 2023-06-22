#include "monty.h"

/**
 * mod - it returns what is left
 *
 * @stack: pointer to the list
 * @line_number: is the number of line where the command is found
 */

void mod(stack_t **stack, unsigned int line_number)
{
	/*declaration*/
	stack_t *tmp = *stack;
	stack_t *count = *stack;

	int b = 0;

	/*cound the number of elemnt found in a stack*/

	for (; count; b++)
		count = count->next;

	/*check if the stack is empty*/
	if (b < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: cant't mod, stack too short\n", line_number);
		frees_struct(stack);
	}
	/*check if the top is 0*/
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees_struct(stack);
	}
	tmp->next->n = tmp->next->n % tmp->n;
	pop(stack, line_number);
}
