#include "monty.h"
/**
 * main - Entry point - interpreter for Monty ByteCodes files
 * @argc: number of arguments passed
 * @argv: array of arguments pased
 * Return: EXIT_SUCCESS for success, EXIT_FAILURE for failure
 */
int main(int argc, char *argv[])
{
	char *line = NULL, *operation = NULL;
	size_t n = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *file_desc = NULL;

	var.is_stack_mode = 0;
	var.stack_length = 0;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_desc = fopen(argv[1], "r");
	if (file_desc == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(_freeLine, &line);
	on_exit(_freeStack, &stack);
	on_exit(_fileDescClose, file_desc);
	while (getline(&line, &n, file_desc) != -1)
	{
		line_number++;
		operation = strtok(line, "\n\t\r ");
		if (operation != NULL && operation[0] != '#')
		{
			execute(operation, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
