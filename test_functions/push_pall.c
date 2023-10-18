#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 100

/* Function Prototypes */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack);

/* Main Function */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        char *token = strtok(line, " \n");
        if (token == NULL || token[0] == '#')
            continue; // Empty line or comment

        if (strcmp(token, "push") == 0)
        {
            opcode_push(&stack, line_number);
        }
        else if (strcmp(token, "pall") == 0)
        {
            opcode_pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

/**
 * opcode_push - pushes an element to the stack
 * @stack: the stack represented as a linked list
 * @line_number: the line number to reference in case of an error
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
    char *token = strtok(NULL, " \n");
    if (token == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(token);
    if (value == 0 && token[0] != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
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
 * opcode_pall - prints all the elements of the stack
 * @stack: the stack represented as a linked list
 */
void opcode_pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
