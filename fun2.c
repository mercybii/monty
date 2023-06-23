#include "monty.h"
#include "commads.h"
#include "prototyp.h"


/**
 * add_dnodeint - adds a new node at the start of alist
 *
 * @head: point to the the list
 * @n: data to store
 *
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;
	/*a new node is aloccated to the memory*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
/*set the value for the new nod*/
	new_node->next = *head;
	new_node->n = n;
	new_node->prev = NULL;
/*update the head of the new list*/

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}

/**
 * free_stack_t - frees list
 * @head: pointer to head of list
 */

void free_stack_t(stack_t **head)
{
	stack_t *traverse;
/*check if the list is empty*/

	if (*head == NULL)
		return;

	while (*head != NULL)
	{
		traverse = *head;
		(*head) = (*head)->next;
		free(traverse);
	}
}
