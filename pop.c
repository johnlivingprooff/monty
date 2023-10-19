#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - Remove the top element from the stack
 * @stack: Double pointer to the stack
 * @line_cnt: Line number of the instruction
 *
 * Return: Void
 */
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: Can't pop an empty stack\n", line_cnt);
		/* Handle the error here */
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
