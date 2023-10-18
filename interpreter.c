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
	int compare;
	instruction_t opc[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop}
	};

	op_word = strtok(line, " \n\t\r");
	for (i = 0; i < sizeof(opc) / sizeof(opc[0]); i++)
	{
		if (op_word != NULL)
		{
			compare = strcmp(op_word, opc[i].opcode);
			if (compare == 0)
				opc[i].f(stack, line_number);
		}
	}
}
