#include "monty.h"

/**
 * check_isdigit - iterates each character of string to check of isdigit
 * @n: integer
 *
 * Return: 0 or -1 on fail
 */
int check_isdigit(const char *n)
{
	int j = 0;

	if (*n == '-')
		j = 1;
	for (; *(n + j) != '\0'; j++)
	{
		if (isdigit(*(n + j)) == 0)
			return (-1);
	}
	return (0);
}

/**
 *  push - adds node to the start of dlinkedlist
 *  @head: head of linked list (node at the bottom of stack)
 *  @line_number: bytecode line number
 *  @n: integer
 */
void push(stack_t **head, unsigned int line_number, const char *n)
{
	if (!head)
		return;

	if (check_isdigit(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_nodeat_end(head, atoi(n)) == -1)
		{
			free_dlist(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *  pop - removes node at front of dlinkedlist
 *  @head: head of linked list (node at the bottom of stack)
 *  @line_number: bytecode line number
 */
void pop(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
		del_nodeat_end(head);
}
