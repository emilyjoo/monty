#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to head node of list
 * @value: value of bytecode file
*/
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - prints all elements in a list
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void pall(stack_t **stack, unsigned int line_number)
{
  

    stack_t *current;

    (void)line_number;  /* Unused parameter */

    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
