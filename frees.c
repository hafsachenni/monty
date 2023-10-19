#include "monty.h"

/**
 * free_head - frees head memory
 * sets it to NULL
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}

/**
 * free_stack - frees nodes in stacks memory
 * @head: first node of a dlistint link
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}
/**
 * free_tokens - frees tokens memory
 */

void free_tokens(void)
{
	int i = 0;

	if (arguments->tokens == NULL)
		return;

	while (arguments->tokens[i])
	{
		free(arguments->tokens[i]);
		i++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}
