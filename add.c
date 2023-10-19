#include "monty.h"

/**
 * add - adds the top 2 elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of monty file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int add = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "l%u: cant add stack is too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	add = (*stack)->n + temp->n;
	temp->n = add;
	pop(stack, line_number);
}
