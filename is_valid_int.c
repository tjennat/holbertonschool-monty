#include "monty.h"

/**
 * is_valid_int - Checks if a string represents a valid integer
 * @str: The string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_int(const char *str)
{
	if (!str)
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}

	return (1);
}
