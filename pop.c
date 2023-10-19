#include "monty.h"

/**
 * opcode_pop - remove the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the instruction
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = *stack;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                status = EXIT_FAILURE;  // Set the status variable to indicate the error
                return;
        }

        *stack = (*stack)->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(temp);
}
