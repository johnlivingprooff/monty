#include "monty.h"

/**
 * add_node - adds node for stack (LIFO)
 * @stack: pointer to list
 * @value: node element to create/add
 */
void add_node(stack_t **stack, int value)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
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
 * add_node_end - adds node for queue (FIFO)
 * @stack: pointer to list
 * @value: node element to create/add
 */
void add_node_end(stack_t **stack, int value)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	current = *stack;
	new->n = value;
	new->next = NULL;

	if (current == NULL)
	{
		new->prev = NULL;
		*stack = new;
	} else
	{
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}
