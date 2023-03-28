#include "main.h"

/**
 * print_char - a function that prints a character
 * @types: List of arguments passed to the fuction
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - a function that prints a string
 * @types: Lists of arguments passed to the function
 * @buffer: Buffer array to hold print
 * @flags:  Calculates currently active flags
 * @width: get the width
 * @precision: Precision value
 * @size: Size
 * Return: NO of chars
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, C;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (C = width - length; C > 0; C--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (C = width - length; C > 0; C--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get the width.
 * @precision: Precision specification
 * @size: Size
 * Return: NO of chars printed
 */

int print_percent(va_list types, char buffer[],
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

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int C = BUFF_SIZE - 2;
	int is_negative = 0;
	long int i = va_arg(types, long int);
	unsigned long int num;

	i = convert_size_number(i, size);

	if (i == 0)
		buffer[C--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)i;

	if (i < 0)
{
		num = (unsigned long int)((-1) * i);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[C--] = (num % 10) + '0';
		num /= 10;
	}

	C++;

	return (write_number(is_negative, C, buffer, flags, width, precision, size));
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

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, C, Sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	i = va_arg(types, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	a[0] = i / j;
	for (C = 1; C < 32; C++)
{
		j /= 2;
		a[C] = (i / j) % 2;
	}
	for (C = 0, Sum = 0, count = 0; C < 32; C++)
	{
		Sum += a[C];
		if (Sum || C == 31)
		{
			char z = '0' + a[C];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
