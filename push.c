#include "monty.h"

/**
 * opcode_push - pushes an element to the stack.
 * @stack: the linked list, reps the stack
 * @line_number: to reference the line with possible error
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		exit(EXIT_FAILURE);

	if (*stack == NULL)
		fprintf(stderr, "L%u: usage: push integer", line_number);

	new->n = (*stack)->n;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;

}
