#include "main.h"

/**
 * get_flags - A functions that calculates Flags that are active
 * @format: prints arguments that are formmated strings
 * @i: Gets the parameter passed.
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int i, Curr_j;
	int Flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (Curr_j = *i + 1; format[Curr_j] != '\0'; Curr_j++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[Curr_j] == FLAGS_CH[i])
			{
				Flags |= FLAGS_ARR[i];
				break;
			}
		if (FLAGS_CH[i] == 0)
			break;
	}
	*i = Curr_j - 1;

	return (Flags);
}
