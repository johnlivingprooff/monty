#include "monty.h"
#define  _POSIX_C_SOURCE 200809L


/**
 * main - interpretes the bytecode
 * @ac: arg counter
 * @av: arg vector
 * Return: Exit Status
 */
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Opening the monty bytecode file */
	file = fopen(av[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	/* read each line of the file */
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		interpret(line, &stack, line_number, file);
	}

	free_s(stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
