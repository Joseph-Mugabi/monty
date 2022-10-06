#include "monty.h"

/**
 * main - the entry into interpreter
 * @argc: argument counter
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		handle_cmd(agv[1]);

	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * handle_cmd - read file
 * @argv: arguments
 *
 */
void handle_cmd(char *argv[])
{
	int fs, is_push = 0;
	unsigned int line = 1;
	ssize_t n_read;
	char *lineptr, *token;
	stack_t *head = NULL;

	fs = open(argv[1], O_RDONLY);
	if (fs == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	lineptr = malloc(sizeof(char) * 10000);
	if (!lineptr)
		return (0);
	n_read = read(fs, lineptr, 10000);
	if (n_read == -1)
	{
		free(lineptr);
		close(fs);
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (is_push == 1)
		{
			push(&head, line, token);
			is_push = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_push = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op(token) != 0)
			{
				get_op(token)(&head, line);
			}
			else
			{
				free_dlist(&head);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&head);
	free(lineptr);
	close(fs);
}
