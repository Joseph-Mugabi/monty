#include "monty.h"

/**
 * _add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += n;
}
#include "monty.h"

/**
 *  _sub - subtract top element of stack from next element and push result
 *  @stack: double pointer to head of stack
 *  @line_number: line number of current operation
 *
 *  Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}

#include "monty.h"

/**
 *  _div - divide second element of stack by top element
 *  @stack: double pointer to head of stack
 *  @line_number: line number of current operation
 *
 *  Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	if (n == 0)
	{
		dprintf(STDOUT_FILENO,
				"L%u: division by zero\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}
#include "monty.h"

/**
 *  _mul - multiply top two elements of stack and push result
 *  @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= n;
}
#include "monty.h"

/**
 * _mod - compute remainder (modulus) of second element divided by top element
 *  @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 *  Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	if (n == 0)
	{
		dprintf(STDOUT_FILENO,
				"L%u: division by zero\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}
