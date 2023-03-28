#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - a function that prints an unsigned number
 * @types: List a of arguments
 * @buffer: A buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int C = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[C--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[C--] = (num % 10) + '0';
		num /= 10;
	}

	C++;

	return (write_unsgnd(0, C, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - a function that prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: A buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int C = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[C--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[C--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[C--] = '0';

	C++;

	return (write_unsgnd(0, C, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - a function that prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: A buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: A buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - a functiont that prints a hexadecimal number in lower or upper 
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: A buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @flag_ch: Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int C = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[C--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[C--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[C--] = flag_ch;
		buffer[C--] = '0';
	}

	C++;

	return (write_unsgnd(0, C, buffer, flags, width, precision, size));
}
