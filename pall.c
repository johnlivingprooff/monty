#include "monty.h"

/**
 * opcode_pall - prints all the values on the stack, top to bottom
 * @stack: the doubly linked list, rep stack
 * @line_number: the line of the insttruction
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	size_t count = 0;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
		count += 1;
	}
}
