#include "main.h"
/**
 * get_size - determain  the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int size = 0;

	if (format[cur_i] == 'l')
		size = S_LONG;
	else if (format[cur_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;

	return (size);
}
