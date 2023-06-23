#include "monty.h"
#include "commads.h"


/**
 * mul - multiplies top two elements, stores sum in
 * second to top and pops top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */

void mul(stack_t **stack, unsigned int line_number)
{
	/*declation of variables*/

	stack_t *temp = *stack;
	stack_t *counter = *stack;
	int i = 0;
/*count the number of element in the stack*/

	for (; counter; i++)
		counter = counter->next;
/*check if the stack is empty or if it is less than 2*/
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		frees_struct(stack);/* free the memory*/
	}
	temp->next->n = temp->n * temp->next->n;
	pop(stack, line_number);
}

/**
 * mod - returns whats left of division of top two elements,
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */

void mod(stack_t **stack, unsigned int line_number)
{
	/*declaretion of variables*/
	stack_t *temp = *stack;
	stack_t *counter = *stack;
	int i = 0;
/*count the number of element in the stack*/
	for (; counter; i++)
		counter = counter->next;
/*check if the stack is empty or lessthan two*/
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		frees_struct(stack);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees_struct(stack);
	}
	temp->next->n = temp->next->n % temp->n;
	pop(stack, line_number);
}

/**
 * pchar - prints all the character at the top the list
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */

void pchar(stack_t **stack, unsigned int line_number)
{
/*check if tha stack is empty*/
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		frees_struct(stack);
	}
/*check if tha value is an ASCII*/
	if ((*stack)->n > 31 && (*stack)->n < 127)
	{
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		frees_struct(stack);
	}
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	temp = *stack;
	if (!temp)
	{
		putchar('\n');
		return;
	}
	while (temp)
	{
		if (temp->n > 31 && temp->n < 127)
			putchar(temp->n);
		else
			break;
		temp = temp->next;
	}
	putchar('\n');
}
