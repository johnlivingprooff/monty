#include "monty.h"

/**
 * main - interpretes the bytecode
 * @ac: arg counter
 * @av: arg vector
 * Return: Exit Status
 */
int main(int ac, char **av)
{
	FILE *file;
	char *filename, *line = NULL;
	unsigned int line_number = 0;
	ssize_t read;
	size_t len = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Opening the monty bytecode file */
	filename = av[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	/* read each line of the file */
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		interpret(line, &stack, line_number);
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
