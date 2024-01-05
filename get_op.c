#include "monty.h"

/**
 * get_op_func - Gets the function pointer for the specified opcode
 * @opcode: The opcode to look up
 * Return: Function pointer for the opcode, or NULL if not found
 */

void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
