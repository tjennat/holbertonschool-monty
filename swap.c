#include "monty.h"

/**
 * swap - Implements the swap opcode
 * @stack: The stack
 * @line_number: Line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = (*stack)->prev;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}
