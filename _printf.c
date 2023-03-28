#include "main.h"

void print_buffer(char Buffer[], int *Buff_end);

/**
 * _printf - function returns number of charachters Print
 * excluding the null byte used to end output to strings
 * @format: Format of the string
 * Return: -1 if NULL, otherwise P_chars
 */

int _printf(const char *format, ...)
{
	int C, Print = 0, P_chars = 0;
	int flags, width, precision, size, Buff_end = 0;
	va_list list;
	char Buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	
	va_start(list, format);
	
	for (C = 0; format && format[C] != '\0'; C++)
	{
		if (format[C] != '%')
		{
			Buffer[Buff_end++] = format[C];
			if (Buff_end == BUFF_SIZE)
				print_buffer(Buffer, &Buff_end);
			P_chars++;
		}
		else
		{
			print_buffer(Buffer, &Buff_end);
			flags = get_flags(format, &C);
			width = get_width(format, &C, list);
			precision = get_precision(format, &C, list);
			size = get_size(format, &C);
			++C;
			Print = handle_print(format, &C, list, Buffer,
					flags, width, precision, size);
			if (Print == -1)
					return (-1);
			P_chars += Print;
		}
	}
	print_buffer(Buffer, &Buff_end);

	va_end(list);

	return (P_chars);
}

/**
 * print_buffer - Prints the contents of the Buffer if it exist
 * @Buffer: Array of chars
 * @Buff_end: Index at which to add next char, represents the length.
 */

void print_buffer(char Buffer[], int *Buff_end)
{
	if (*Buff_end > 0)
		write(1, &Buffer[0], *Buff_end);

	*Buff_end = 0;
}
