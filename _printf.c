#include "main.h"
#include <stdio.h>
#include <stdarg.h>
void buffer_print(char buffer[], int *buffer_index)
/**
 * _printf - print the function
 * @formart: input value
 * Return: the character to be printed
 */
int _printf(const char *format, ...)
{
	char buffer_1[BUFFER_SIZE];
	int m;
	int ptint = 0;
	int flag, width_1, precise, size;
	int buffer_index = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	m = 0;
	for (; format && format[m] != '\0'; m++)
	{
		if (format[m] != '%')
		{
			buffer[buffer_index++] == format[m];
			if (buffer_index == BUFFER_SIZE)
			{
				buffer_print(buffer, &buffer_index);
			}
			print_char++;
		}
		else
		{
			buffer_print(buffer, &buffer_index);
			flag = get_flag(format, &m);
			width = get_width(formt, @m, args);
			precise = get_precise(format, @m, args);
			size = get_length(format, &m);
			++m;
			print = solve_print(format, &m, args, buffer, flag, width, precise, size);
			if(print == -1)
			{
				return (-1);
			}
			print_char = print_char + print;
		}
	}
	buffer_print(buffer, &buffer_index);
	va_end(args);
	return (print_char);
}
/**
 * buffer_print - display the content of the buffer
 * @buffer: list of char
 * @buffer_index: place to add the char
 */
void buffer_print(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index)
	}
	*buffer_index = 0;
}

