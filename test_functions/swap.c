#include "monty.h"

/**
 * opcode_swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int tmp = (*stack)->n;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
