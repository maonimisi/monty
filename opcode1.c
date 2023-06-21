#include "monty.h"
/**
 * pint - print the value on top of the stack followed by a newline
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current instruction
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	if (var.stack_length == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top_node->n);
}

/**
 * pop - remove the top element from the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current instruction
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (var.stack_length == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_length != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(current);
	var.stack_length--;
}

/**
 * swap - swap the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current instruction
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node;

	if (var.stack_length < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_length == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next_node = (*stack)->next;
	next_node->prev = (*stack)->prev;
	(*stack)->prev->next = next_node;
	(*stack)->prev = next_node;
	(*stack)->next = next_node->next;
	next_node->next->prev = *stack;
	next_node->next = *stack;
	*stack = next_node;
}

/**
 * add - add the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current instruction
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (var.stack_length < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	sum += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += sum;
}

/**
 * nop - no operation performed
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current instruction
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
