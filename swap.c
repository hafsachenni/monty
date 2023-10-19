#include "monty.h"

/**
 * swap - swaps the top 2 elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line num in monty file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: cant swap stack is too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
