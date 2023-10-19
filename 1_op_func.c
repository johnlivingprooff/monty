#include "monty.h"

/**
 * opcode_push - pushes an element to the stack.
 * @stack: the linked list, reps the stack
 * @line_number: to reference the line with possible error
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *num = strtok(NULL, " \n\t\r");

	value = atoi(num);
	if (value == 0 && num[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		/*fclose(glb.file);*/
		/*free(glb.line);*/
		exit(EXIT_FAILURE);
	}
	if (QUEUE)
		add_node_end(stack, value);
	else
		add_node(stack, value);
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
	stack_t *pop;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		/*fclose(glb.file);*/
		/*free(glb.line);*/
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
		/*fclose(glb.file);*/
		/*free(glb.line);*/
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
