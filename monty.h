#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct interpreter_s - struct to contain the main variables of the
 * Monty interpreter
 * @is_stack_mode: flag to determine if in stack mode (LIFO) vs queue mode (FIFO)
 * @stack_length: length of the stack
 */
typedef struct interpreter_s
{
	int is_stack_mode;
	size_t stack_length;
} interpreter_s;

#define STACK 0
#define QUEUE 1

/* global struct to hold flag for queue and stack length */
extern interpreter_s var;


/*execute*/
void execute(char *op, stack_t **stack, unsigned int line_number);

/*helpers*/
void _setStackFormat(stack_t **stack, unsigned int line_number);
void _setQueueFormat(stack_t **stack, unsigned int line_number);
stack_t *_addNode(stack_t **stack, const int value);

/*memory*/
void _freeStack(int status, void *arg);
void _fileDescClose(int status, void *arg);
void _freeLine(int status, void *arg);

/*opcode1*/
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*opcode2*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
