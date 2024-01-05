#include "monty.h"

/**
 * push - Implements the push opcode
 * @stack: The stack
 * @line_number: Line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, DELIMITERS);
	int value;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_valid_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(arg);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(arg);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
