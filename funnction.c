#include "monty.h"


/**
 * add_dnodeint - add anew node at the beginging of the list
 *
 * @mercy: is the point to the list
 * @n: data to be stored
 *
 * Return: NULL when it fail
 */

stack_t *add_dnodeint(stack_t *mercy, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node = NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*setting a value to the new node*/
	new_node->next = *mercy;
	new_node->n = n;
	new_node->prev = NULL;

	/*uppdeintin the node to the list*/
	if (*mercy == NULL)
	{
		*mercy = new_node;
	}
	else
	{
		/*check if th node is empty*/
		(*mercy)->prev = new_node;
		*mercy = new_node;
	}
	return (new_node);
}

/**
 * free_stack_t - is to free the list
 * @mercy- a pointer to the head
 */

void free_stack_t(stack_t **mercy)
{
	stack_t *traverse;

	/*check is the list is empty*/
	if (*mercy == NULL)
		return;

	/*free the memmory*/
	{
		traverse = *mercy;
		(*mercy) = (*mercy)->next;
		free(traverse);
	}
}
