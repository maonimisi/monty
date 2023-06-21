#include "monty.h"
/**
 * execute - confirm and execute instruction
 * @operation: instruction to check
 * @line_number: script line number
 * @stack: double pointer pointing to the stack's top
 * Return: void
 */
void execute(char *operation, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (strcmp(codes[i].opcode, operation) == 0)
		{
			codes[i].f(stack, line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
		line_number, operation);
	exit(EXIT_FAILURE);
}
