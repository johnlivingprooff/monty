#include "monty.h"

/**
 * opcode_push - pushes an element to the stack.
 * @stack: the linked list, reps the stack
 * @line_number: to reference the line with possible error
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	char *num;
	int value;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	num = strtok(NULL, " \n");

	if (num == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(num);
	if (value == 0 && num[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;

}

/**
 * opcode_pop - Remove the top element from the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: Void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->next != NULL)
		temp->next->prev = NULL;

	*stack = temp->next;
	free(temp);
}

/**
 * opcode_pall - prints all the values on the stack, top to bottom
 * @stack: the doubly linked list, rep stack
 * @line_number: the line of the insttruction
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
		line_number++;
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
	int tmp = (*stack)->n;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

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
