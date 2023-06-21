#include "monty.h"
/**
 * _hasOnlyDigits - checks if a string argument contains only digits
 * @arg: string to check
 * Return: 0 if it contains only digits, else 1
 */
static int _hasOnlyDigits(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (!isdigit(arg[i]))
			return (1);
	}
	return (0);
}

/**
 * push - push an integer element onto the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || _hasOnlyDigits(arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	if (!_addNode(stack, value))
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_length++;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer pointing to the top of the stack
 * @line_number: index of argument/instruction
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)(line_number);

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		if (current == *stack)
			return;
	}
}
