#include "monty.h"

/**
 * getopcode_func - gets the opcode  its corresponding function
 * @line_number: line num in monty
 * @opcode: opcode in file
 * @stack: pointer to the top of stack
 */

void getopcode_func(stack_t **stack, unsigned int line_number, char *opcode)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (operations[i].opcode != NULL)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
		{
			operations[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_list(*stack);
	exit(EXIT_FAILURE);
}
