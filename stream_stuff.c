#include "monty.h"

/**
 * getting_stream_failed - handles the error
 * @filename: the failed file
 */
void getting_stream_failed(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * get_stream = gets the stream for reading from file
 * @file name: the specified file
 */

void get_stream(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		getting_stream_failed(filename);
	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		getting_stream_failed(filename);
	}
}

/**
 * close_stream - Closes the file stream and sets it to NULL
 */

void close_stream(void)
{
	if (arguments->stream == NULL)
		return;

	fclose(arguments->stream);
	arguments->stream = NULL;
}
