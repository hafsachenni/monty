#include "monty.h"

/**
 * free_list - frees the doubly linked list
 * @stack: top of the stack
 */

void free_list(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
