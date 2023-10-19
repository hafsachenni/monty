#include "monty.h"
#include <stdio.h>
/**
 * execute - executes monty opcodes
 * @file: file to be read and interpreted
 */

void execute(FILE *file)
{
	char *lineptr = NULL;
	char *token;
	unsigned int line_number = 1;
	size_t char_count = 0;
	ssize_t read;
	stack_t *stack = NULL;

	while ((read = getline(&lineptr, &char_count, file)) != -1)
	{
		token = strtok(lineptr, " \n\t");
		if (token == NULL || token[0] == '#')
		{
			line_number++;
			continue;
		}

		getopcode_func(&stack, line_number, token);
		line_number++;
	}

	free_list(stack);
	free(lineptr);
	fclose(file);
}
