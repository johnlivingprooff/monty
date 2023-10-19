#include "monty.h"

int p_mode;

/**
 * stck - follows LIFO structure
 * @stack: the d-linked list
 * @l_number: the line number
 */
void stck(stack_t **stack, unsigned int l_number)
{
	(void)stack;
	(void)l_number;

	p_mode = 0;
}

/**
 * queue - follows FIFO structure
 * @stack: the d-linked list
 * @l_number: the line number
 */
void queue(stack_t **stack, unsigned int l_number)
{
	(void)stack;
	(void)l_number;

	p_mode = 1;
}

/**
 * opcode_push - pushes an element to the stack.
 * @stack: the linked list, reps the stack
 * @line_number: to reference the line with possible error
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *num = strtok(NULL, " \n\t\r");

	value = atoi(num);
	if (value == 0 && num[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		/*fclose(glb.file);*/
		/*free(glb.line);*/
		exit(EXIT_FAILURE);
	}
	if (p_mode)
		add_node_end(stack, value);
	else
		add_node(stack, value);
}
