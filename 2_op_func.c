#include "monty.h"

/**
 * opcode_add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: the line number
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	int len = 0, sum;
	stack_t *node = *stack;

	while (node)
	{
		node = node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	sum = node->n + node->next->n;
	node->next->n = sum;
	*stack = node->next;
	free(node);
}

/**
 * opcode_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to stack
 * @line_number: the line number
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	int len = 0, min;
	stack_t *node = *stack;

	while (node)
	{
		node = node->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	min = node->next->n - node->n;
	node->next->n = min;
	*stack = node->next;
	free(node);
}

/**
 * opcode_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer to stack
 * @line_number: the line number;
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int len = 0, mul;

	for (; node != NULL; len++)
		node = node->next;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	mul = node->next->n * node->n;
	node->next->n = mul;
	*stack = node->next;
	free(node);
}

/**
 * opcode_div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: the line number;
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int len, div;

	for (len = 0; node != NULL; len++)
		node = node->next;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	if (node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = node->next->n / node->n;
	node->next->n = div;
	*stack = node->next;
	free(node);
}

/**
 * opcode_mod - computes the rest of the division
 * of the second top element of the stack by the top element of the stack.
 * @stack: pointer to stack
 * @line_number: the line number;
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int len, mod;

	for (len = 0; node != NULL; len++)
		node = node->next;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	if (node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = node->next->n % node->n;
	node->next->n = mod;
	*stack = node->next;
	free(node);
}
