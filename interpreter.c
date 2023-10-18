#include "monty.h"

/**
 * interpret - interprets the opcode
 * @line: where the opcode is
 * @stack: linked list, rep stack
 * @line_number: the line number
 */
void interpret(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_word;
	size_t i;

	instruction_t opc[] = {
		{"push", opcode_push},
		{"pall", opcode_pall}
	};

	for (i = 0; i < sizeof(opc) / sizeof(opc[0]); i++)
	{
		op_word = strtok(line, " \n\t\r");
		if (op_word != NULL)
		{
			if (strcmp(op_word, opc[i].opcode) == 0)
				opc[i].f(stack, line_number);
		}
	}
}
