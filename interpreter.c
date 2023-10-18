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
	size_t i, len = 0;
	unsigned int line_number = 0;
	ssize_t read;

	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall}
	};

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
		stack_t *stack;

		/* line contains push */
		for (i = 0; i < sizeof(opcodes) / sizeof(opcodes[0]); i++)
		{
			if (strstr(line, opcodes[i].opcode) != NULL)
			{
				char *token = strtok(strstr(line, opcodes[i].opcode) + strlen(opcodes[i].opcode), " ");
				int value = = atoi(token);

				stack->n = value;
				opcodes[i].f(&stack, line_number);
			}
		}
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
