#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @stack: pointer to the top of stack
 * @line_number: line num in monty
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "l%u: cant pop, its an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
