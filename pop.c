#include "monty.h"

/**
 * pop - Implements the pop opcode
 * @stack: The stack
 * @line_number: Line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
