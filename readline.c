#include "monty.h"

/**
 * read_line - reads each line of the function
 * @file: the file to read
 * Return: num of chars read / -1
 */
ssize_t read_line(FILE *file)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL;

	read = getline(&line, &len, file);

	return (read);
}
