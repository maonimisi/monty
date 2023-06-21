#include "monty.h"
/**
 * _setStackFormat - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 * Return: void
 */
void _setStackFormat(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.is_stack_mode = STACK;
}

/**
 * _setQueueFormat - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 * Return: void
 */
void _setQueueFormat(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.is_stack_mode = QUEUE;
}

/**
 * _addNode - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @value: value to add to the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *_addNode(stack_t **stack, const int value)
{
	stack_t *new_node;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	if (var.is_stack_mode == STACK || var.stack_length == 0)
		*stack = new_node;
	return (new_node);
}
