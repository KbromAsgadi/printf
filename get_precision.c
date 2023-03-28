
#include "main.h"

/**
 * get_precision - a function that calculates the PR for the function printing
 * @format: prints arguments that are formated strings
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: PR.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int Curr_j = *i + 1;
	int PR = -1;

	if (format[Curr_j] != '.')
		return (PR);

	PR = 0;

	for (Curr_j += 1; format[Curr_j] != '\0'; Curr_j++)
	{
		if (is_digit(format[Curr_j]))
		{
			PR *= 10;
			PR += format[Curr_j] - '0';
		}
		else if (format[Curr_j] == '*')
		{
			Curr_j++;
			PR = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = Curr_j - 1;

	return (PR);
}
