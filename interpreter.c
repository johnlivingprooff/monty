#include "monty.h"

/**
 * interpret - interprets the opcode
 * @line: where the opcode is
 * @stack: linked list, rep stack
 * @line_number: the line number
 */
void interpret(char *line, stack_t **stack, unsigned int line_number)
{
	char *token, *op_word;
	size_t value, i;
	stack_t *new_stack;

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

			new_stack = malloc(sizeof(stack_t));

			if (new_stack == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}

			new_stack->n = value;
			new_stack->prev = NULL;
			new_stack->next = *stack;

			if (*stack != NULL)
				(*stack)->prev = new_stack;
			*stack = new_stack;

			opc[i].f(stack, line_number);
		}
	}
}
