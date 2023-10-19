#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

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
 * struct arg_s - hold variables
 * @stream: File that connects to the stream from file
 * @line: string which will be the line of the text
 */
typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	int stack_length;
	int stack;
} arg_t;

extern arg_t *arguments;

/* operation code functions */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* ------------------------tool-------------------*/

void validate_arguments(int argc);
void initialize_arguments();
void malloc_failed();
void pint(stack_t **stack, unsigned int line_number);
void getting_stream_failed(char *filename);
void free_arguments();
void get_stream(char *filename);
void free_head();
void free_stack(stack_t *head);
void free_tokens(void);
void tokenize_line(void);
void get_instruction(void);
void invalid_instruction(void);
void close_stream(void);
void run_instruction(void);
int is_number(char *str);

#endif
