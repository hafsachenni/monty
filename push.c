#include "monty.h"

/**
 * push - function that pushes a value to the top of the stack
 * @stack: pointer to a pointer of the stack
 * @line_number: line num representing where the push op will be called
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	int n;
	char *arg_token = strtok(NULL, " \n\t");

        if (arg_token == NULL)
        {
                fprintf(stderr, "L%u: USAGE: push integer\n", line_number);
                free_list(*stack);
                exit(EXIT_FAILURE);
        }

	n = atoi(arg_token);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	free(*stack);
	exit(EXIT_FAILURE);
	}

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *stack;
	if (*stack)
	(*stack)->prev = newnode;
	*stack = newnode;
}
