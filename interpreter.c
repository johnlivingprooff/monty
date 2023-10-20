#include "monty.h"

/**
 * interpret - interprets the opcode
 * @line: where the opcode is
 * @stack: linked list, rep stack
 * @l_count: the line number
 * @file: the monty file
 */
void interpret(char *line, stack_t **stack, unsigned int l_count, FILE *file)
{
	char *op_word;
	size_t i = 0;
	instruction_t opc[] = {
		{"push", opcode_push}, {"mod", opcode_mod},
		{"pall", opcode_pall}, {"div", opcode_div},
		{"pint", opcode_pint}, {"mul", opcode_mul},
		{"pop", opcode_pop}, {"sub", opcode_sub},
		{"swap", opcode_swap}, {"add", opcode_add},
		{"nop", opcode_nop}, {"pchar", opcode_pchar},
		{"pstr", opcode_pstr}, {"rotl", opcode_rotl},
		{"rotr", opcode_rotr}, {"stack", stck},
		{"queue", queue}, {NULL, NULL}
	};

	op_word = strtok(line, " \n\t\r");

	if (op_word && op_word[0] == '#') /* for comments */
		return;

	while (op_word && opc[i].opcode)
	{
		if (strcmp(op_word, opc[i].opcode) == 0)
		{
			opc[i].f(stack, l_count);
			return;
		}
		i++;
	}
	if (op_word != NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", l_count, op_word);
		fclose(file);
		free(line);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}
}
