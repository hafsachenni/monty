#include "monty.h"

/**
 * main - interpreter for monty files
 * @argc: arg count
 * @argv: array of strings
 * Return: 0
 */

int main(int argc, char **argv)
{
	FILE *file;	/*file to open and read from*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}


	execute(file);

	return (0);
}
