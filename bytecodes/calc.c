#include "monty.h"

/**
 *  _add - adds the top two elements in stack
 *  @head: top node
 *  @line_number: node number
 */
void _add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->next);
	(*head)->prev = NULL;
}
/**
 *  _sub - subtract second node from top node
 *  @head: top of list
 *  @line_number: line of command
 */
void _sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *  _mul - multiply second node and top node
 *  @head: top of list
 *  @line_number: line of command
 */
void _mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *  _div - divide second node from top node
 *  @head: top of list
 *  @line_number: line of command
 */
void _div(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 *  _mod - mod second node from top node
 *  @head: top of list
 *  @line_number: line of command
 */
void _mod(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == 0 || (*head)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*head)->next->n %= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
