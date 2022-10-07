#include "monty.h"
/**
 * add_node_at_end - add node to front of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_node_at_end(stack_t **head, int n)
{
	stack_t *new_node;

	if (!head)
		return (-1);

	/* malloc and set new node data */
	new_node = malloc(sizeof(struct stack_s));
	if (!new_node)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new_node->n = n;

	/* account for empty linked list */
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else /* insert to front */
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (0);
}
/**
 * del_end_node - deletes node at end of doubly linked list
 * @head: pointer to head of doubly linked list
 */
void del_end_node(stack_t **head)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
}
/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @head: pointer to head of list
 */
void free_dlist(stack_t **head)
{
	/* return if empty list */
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
