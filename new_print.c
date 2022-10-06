#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @head: head of the list
 * @line_number: bytecode line number
 *
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!head || !head)
		return;

	(void) line_number;
	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print top node in stack
 * @head: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pchar - print top node in stack as ascii letter
 * @head: head of list
 * @line_number: bytecode line number
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) >= 0 && ((*head)->n) <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 *  nop - do nothing
 *  @head: head of list
 *  @line_number: bytecode line number
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 *  pstr - print top nodes in stack as ascii letter
 *  and stop only if end of stack, node is 0, or not in ascii table
 *  @head: head of list
 *  @line_number: bytecode line number
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t temp;

	if (!head || !*head)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	while ((temp != NULL) && (temp->n != 0) &&
			(temp->n >= 0) && (temp->n <= 127))
	{
		printf("%c", (temp)->n);
		temp = temp->next;
	}
	printf("\n");
}
