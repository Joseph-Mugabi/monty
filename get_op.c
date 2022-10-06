#include "monty.h"

/**
 * get_op - function to select correct operation function
 * @op: bytecode input (opcode)
 *
 * Return: pointer to correct operation function
 */
void (*get_op(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t valid_ops[] = {
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"pchar", pchar},
		{"nop", nop},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int j;

	for (j = 0; valid_ops[j].f != NULL; j++)
	{
		if (strcmp(op, valid_ops[j].opcode) == 0)
			return (valid_ops[j].f);
	}
	return (NULL)
}
