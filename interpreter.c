#include "monty.h"

/**
 * interpret - interprets the opcode
 * @line: where the opcode is
 */
void interpret(char *line)
{
	char *token, *op_word;
	int value, i;

	instruction_t opc[] = {
		{"push", opcode_push},
		{"pall", opcode_pall}
	};

	for (i = 0; i < sizeof(opc) / sizeof(opc[0]); i++)
	{
		op_word = strstr(line, opc[i].opcode);
		if (op_word != NULL)
		{
			token = strtok(op_word + strlen(opc[i].opcode), " ");
			value = atoi(token);

			stack_t *new_stack = malloc(sizeof(stack_t));

			if (new_stack == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
