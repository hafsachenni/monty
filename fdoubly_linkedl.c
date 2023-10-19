#include "monty.h"

/**
 * free_list - frees the doubly linked list
 * @stack: top of the stack
 */

void free_list(stack_t *stack)
{
	if (stack == NULL)
		return;
	free_list(stack->next);
	free(stack);
}
