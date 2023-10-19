#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_cnt: Line number of the instruction
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_cnt);
		/* Handle the error condition here */
		return;
	}

	stack_t *top = *stack;
	stack_t *second = top->next;

	second->n += top->n;
	*stack = second;
	second->prev = NULL;
	free(top);
}
