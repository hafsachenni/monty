#include "monty.h"

/**
 * pint - prints value at the top of stack followed by nwe line
 * @stack: pointer to the head
 * @line_number: line in the monty file where pint will be called
 * Return: exit with status EXIT_FAILURE if failed
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "line number %u can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
