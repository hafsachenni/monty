#include "monty.h"

/**
 * malloc_failed - Handles the error of malloc
 */
void malloc_failed()
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}
