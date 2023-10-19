#include "monty.h"

/**
 * pop - Remove the top element from the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: Void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
