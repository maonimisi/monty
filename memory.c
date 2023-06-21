#include "monty.h"
/**
 * _freeStack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void _freeStack(int status, void *arg)
{
	stack_t **stack_ptr;
	stack_t *next_node;

	(void)status;

	stack_ptr = (stack_t **)arg;
	if (*stack_ptr)
	{
		(*stack_ptr)->prev->next = NULL;
		(*stack_ptr)->prev = NULL;
	}
	while (*stack_ptr != NULL)
	{
		next_node = (*stack_ptr)->next;
		free(*stack_ptr);
		*stack_ptr = next_node;
	}
	var.stack_length = 0;
}

/**
 * _fileDescClose - close file stream on exit
 * @status: status passed to exit
 * @arg: pointer to file stream
 * Return: void
 */
void _fileDescClose(int status, void *arg)
{
	FILE *file_stream;

	(void)status;
	file_stream = (FILE *)arg;
	fclose(file_stream);
}

/**
 * _freeLine - free line returned by getline
 * @status: exit status
 * @arg: pointer to line
 * Return: void
 */
void _freeLine(int status, void *arg)
{
	char **line_ptr = arg;

	(void)status;

	if (*line_ptr != NULL)
		free(*line_ptr);
}
