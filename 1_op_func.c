#include "monty.h"

/**
 * opcode_pop - Remove the top element from the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: Void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	pop = *stack;
	*stack = pop->next;
	free(pop);
}

/**
 * opcode_pall - prints all the values on the stack, top to bottom
 * @stack: the doubly linked list, rep stack
 * @line_number: the line of the insttruction
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pall = *stack;
	(void)line_number;

	if (pall == NULL)
		return;

	while (pall)
	{
		printf("%d\n", pall->n);
		pall = pall->next;
	}
}

/**
 * opcode_pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the instruction
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * opcode_swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *first, *second;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
}
