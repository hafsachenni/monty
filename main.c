#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - interpreter for monty files
 * @argc: arg count
 * @argv: array of arg tokens
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void) argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

