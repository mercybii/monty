#include "monty.h"

/**
 * division - divides the top elements
 *
 * @stack: pointer to the list
 * @line_number: number of line where command are found
 */

void division(stack_t **stack, unsigned int line_number)
{
	/*declaretion of variables */

	stack_t *t = *stack;
	stack_t *count = *stack;
	int b = 0;
/*count the number of elemnt in the stack */
	for(; count; b++)
		count = count->next;
/* check if the stack is empty*/
if (b < 2 || !*stack || !(*stack)-> next || !stack)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
frees_struct(stack);
}
if (t->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
frees_struct(stack);
}
t->next->n = t->next->n /t->n;
pop(stack, line_number);
}
