#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>

/**
 * validate_arguments - checks the number of xommand line arguments
 * @argc: the number of command-line arguments.
 */

void validate_arguments(int argc)
{
	if (argc == 2)
		return;

	fprintf(stderr, "Usage: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * free_arguments - free arguments memory
 */

void free_arguments()
{
	if (arguments == NULL)
		return;
	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction= NULL;
	}
	free_head();
	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}
	free(arguments);
}
/**
 * initialize_arguments - initializes a pointer to
 * arg_s structure.
 */
void initialize_arguments()
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
}
