#include "monty.h"

/**
 * opcode_nop - does nothing
 * @stack: not used
 * @line_number: also not used
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* literally does nothing */
}

/**
 * opcode_pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	if (node->n > 127 || node->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", node->n);
}

/**
 * opcode_pstr - prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node)
	{
		if (node->n > 127 || node->n < 1)
			break;
		printf("%c", node->n);
		node = node->next;
	}

	putchar(10);
}

/**
 * opcode_rotl - rotates the stack to the top.
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *rotl;
	(void)line_number;

	if (node == NULL || node->next == NULL)
		return;

	rotl = node->next;
	rotl->prev = NULL;

	while (node->next != NULL)
		node = node->next;

	node->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = node;
	*stack = rotl;
}

/**
 * opcode_rotr - rotates the stack to the bottom.
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (node->next)
		node = node->next;

	node->next = *stack;
	node->prev->next = NULL;
	node->prev = NULL;
	(*stack)->prev = node;
	*stack = node;
}
