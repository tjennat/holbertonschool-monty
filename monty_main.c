#include "monty.h"

/**
 * main - Entry point for the Monty program
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		instruction = parse_line(line, line_number);
		if (instruction.f)
			instruction.f(&stack, line_number);
	}

	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
