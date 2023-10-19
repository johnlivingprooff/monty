#include "monty.h"

/**
 * free_s - frees malloc'd space
 * @stack: the node that is being free'd
 */
void free_s(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack->next;
		free(stack);
		stack = node;
	}
}
