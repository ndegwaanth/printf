#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_m = *i + 1;
	int precise = -1;

	if (format[curr_m] != '.')
		return (precise);

	precise = 0;

	for (curr_m += 1; format[curr_m] != '\0'; curr_m++)
	{
		if (is_digit(format[curr_m]))
		{
			precise *= 10;
			precise += format[curr_m] - '0';
		}
		else if (format[curr_m] == '*')
		{
			curr_m++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_m - 1;

	return (precise);
}
