#include "monty.h"
#include <ctype.h>

/**
 *  pall - print all values on `stack' starting from the top
:wq *  @stack: double pointer to head of stack
 * @line_number: line number being executed from script file
 *
 *  Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}

/**
 *  pchar - print character from top of stack
 *  @stack: double pointer to top of stack
 *  @line_number: line number of current operation
 *
 *  Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (var.stack_len < 1)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
/**
 * pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pint, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 *  pstr - print string from stack of ints up to null byte,
 *  first non-ascii character, or end of stack
 *  @stack: double pointer to head of stack
 *  @line_number: line number of current operation
 *  Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ch;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		ch = temp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		temp = temp->next;
		if (temp == *stack)
			break;
	}
	putchar('\n');
}

/**
 * nop - no operation performed
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 *  Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
