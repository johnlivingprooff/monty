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
	char *filename = NULL;
	char line[1024];

	unsigned int line_number = 0;
	
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
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		interpret(line, &stack, line_number);
	}

	while (stack != NULL)
	{
		stack_t *temp;
		temp = stack;
		
		stack = stack->next;
		free(temp);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
