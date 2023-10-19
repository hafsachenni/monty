#define _GNU_SOURCE

#include "monty.h"
arg_t *arguments = NULL;

/**
 * main - Entry point
 * @argc: number of the command-line arguments
 * @argv: string of the command-line arguments
 * Return: returns 0 (succeed)
 */
int main(int argc,char **argv)
{
	size_t n = 0;

	validate_arguments(argc);
	initialize_arguments();
	get_stream(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != 0)
	{
		arguments->line_number += 1;
		tokenize_line();
		get_instruction();
		run_instruction();
		free_tokens();
	}
	close_stream();
	free_arguments();

	return (0);
}
