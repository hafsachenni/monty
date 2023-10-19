#include "monty.h"
/**
 * invalid_instruction - handle unkown instractions
 */
void invalid_instruction(void)
{
	dprintf(2, "L%d: unkown instruction %s\n",
			arguments->line_number, arguments->tokens[0]);
	close_stream();
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}
/**
 * get_instruction - sets the instruction based on the fisrt token
 * in the input line.
 */

void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0)
		return;

	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguments->tokens[0])
				== 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * run_instruction - runs the instruction
 */

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0)
		return;

	arguments->instruction->f(&stack, arguments->line_number);
}
