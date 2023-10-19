#include "monty.h"

/**
 * execute_opcodes - executes monty opcodes
 * @file: file to be read and interpreted
 */

void execute_opcodes(FILE *file)
{
	char *lineptr = NULL;
	char *token;
	unsigned int line_num = 1;
	size_t char_count = 0;
	ssize_t read;
	stack_t *stack = NULL;

	while ((read = getline(&lineptr, &char_count, file)) != -1)
	{
		token = strtok(lineptr, " \n\t");
		if (token == NULL || token[0] == '#')
		{
			line_num++;
			continue;
		}

		get_opcode(&stack, line_num, token);
		line_num++;
	}

	free_doublyllist(stack);
	free(lineptr);
	fclose(file);
}
