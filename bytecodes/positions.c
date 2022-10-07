#include "monty.h"

/**
 *  rotr - rotate so only bottom node of stack becomes first one
 *  @head: node to be rotated
 *  @line_number: node number
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*head)->prev = tmp;
		tmp->next = *head;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*head) = (*head)->prev;
	}
}

/**
 *  rotl - rotate so top of stack becomes last one, second becomes first one
 *  @head: node to be rotated
 *  @line_number: node number
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*head)->prev = tmp;
		tmp->next = *head;
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		tmp->next->next = NULL;
	}
}

/**
 *  swap - swap locations of previous stack with the top stack
 *  @head: node to be swapped
 *  @line_number: node number
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	if (temp->next != NULL)
	{
		(*head)->next = temp->next;
		(*head)->prev->next = *head;
	}
	else
	{
		temp->prev->next = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *head;
	(*head) = temp;
}
