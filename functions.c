#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char_alpha(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char s = va_arg(types, int);

	return (handle_write_char(s, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string_values(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length_one = 0, m;
	char *sting = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[length_one] != '\0')
		length_one++;

	if (precision >= 0 && precision < length_one)
		length_one = precision;

	if (width > length_one)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], length_one);
			for (m = width - length_one; m > 0; m--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (m = width - length_one; m > 0; m--)
				write(1, " ", 1);
			write(1, &string[0], length_one);
			return (width);
		}
	}

	return (write(1, string, length_one));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent_output(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int_values(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	int is_negative_one = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_negative_one = 1;
	}

	while (number > 0)
	{
		buffer[m--] = (number % 10) + '0';
		number /= 10;
	}

	m++;

	return (write_number(is_negative_one, m, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary_values(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int k, p, j, sum;
	unsigned int array[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	k = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	array[0] = k / p;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		array[i] = (k / p) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += array[j];
		if (sum || j == 31)
		{
			char z = '0' + array[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
