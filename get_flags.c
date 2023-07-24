#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, curr_i;
	int flag = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (m = 0; FLAGS_CHAR[m] != '\0'; m++)
			if (format[curr_i] == FLAGS_CHAR[m])
			{
				flag |= FLAGS_ARRAY[m];
				break;
			}

		if (FLAGS_CHAR[m] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
