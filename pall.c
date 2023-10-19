#include "monty.h"

/**
 * pall - prints all elemants of the stack
 * @stack: double pointer to top of stack
 * @line_number: line num in the monty file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
