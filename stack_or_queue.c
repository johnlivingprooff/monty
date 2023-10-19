#include "monty.h"


/**
 * stck - follows LIFO structure
 * @stack: the d-linked list
 * @l_number: the line number
 */
void stck(stack_t **stack, unsigned int l_number)
{
	(*stack)->n = STACK;
	(void)l_number;
}

/**
 * queue - follows FIFO structure
 * @stack: the d-linked list
 * @l_number: the line number
 */
void queue(stack_t **stack, unsigned int l_number)
{
	(*stack)->n = QUEUE;
	(void)l_number;
}
