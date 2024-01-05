#include "monty.h"

/**
 * parse_line - Parses a line of Monty bytecode
 * @line: Line of Monty bytecode
 * @line_number: Line number in the file
 * Return: The corresponding instruction_t structure
 */

instruction_t parse_line(char *line, unsigned int line_number)
{
	instruction_t instruction = {NULL, NULL};
	char *opcode = strtok(line, DELIMITERS);

	if (opcode && opcode[0] != '#')
	{
		instruction.opcode = strdup(opcode);
		if (!instruction.opcode)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		instruction.f = get_op_func(instruction.opcode);
		if (!instruction.f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(instruction.opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(instruction.opcode);
	return (instruction);
}
