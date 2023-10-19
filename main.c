#include "monty.h"

/**
 * main - interpreter for monty files
 * @argc: arg count
 * @argv: array of strings
 * Return: 0
 */

int main(int ac, char *av[])
{
	FILE *file;	/*file to open and read from*/
	char *m_file = av[1];

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(m_file, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}


	execute(file);

	return (0);
}
