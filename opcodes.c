#include "monty.h"

/**
 * push - pushe an element to the stack
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void push(stack_t **stack, unsigned int line)
{
	stack_t *new_node;
	int dt;

	new_node = malloc(sizeof(size_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!monty.arg || (is_digit(monty.arg) == -1))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	dt = atoi(monty.arg);
	new_node->n = dt;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*stack))
	{
		(*stack) = new_node;
		return;
	}
	/* if stack is not NULL */
	new_node->next = (*stack);
	(*stack)->prev = new_node;
	(*stack) = new_node;
}

/**
 * pall - print all elements in a list
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void pall(stack_t **stack, unsigned int line)
{
	stack_t *tp;
	(void)line;

	tp = *stack;
	while (tp)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * pint - print element at the top of the list
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void pint(stack_t **stack, unsigned int line)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove the top element of the stack
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	tp = *stack;
	if (!(*stack)->next)
		*stack = NULL;
	else
		*stack = (*stack)->next, (*stack)->prev = NULL;
	free(tp);
}

/**
 * swap - swap the top two elements of the stack
 * @stack: double pointer to head node of list
 * @line: line number of bytecode file
*/
void swap(stack_t **stack, unsigned int line)
{
	stack_t *tp;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tp = (*stack)->next;
	if (tp->next) 
	{
		(*stack)->next = tp->next;
		tp->next->prev = *stack;
	}
	else 
		(*stack)->next = NULL;
	(*stack)->prev = tp;
	tp->next = *stack;
	tp->prev = NULL;
	*stack = tp;
}
