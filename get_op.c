#include "monty.h"

/**
 * get_op - function to select correct operation function
 * @ops: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op(char *ops))(stack_t **stack, unsigned int line_number)
{
	instruction_t valid_ops[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (valid_ops[i].f != NULL)
	{
		if (strcmp(ops, valid_ops[i].opcode) == 0)
			return (valid_ops[i].f);
		i++;
	}
	return (NULL);
}
