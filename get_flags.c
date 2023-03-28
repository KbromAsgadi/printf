#include "main.h"

/**
 * get_flags - A functions that calculates Flags that are active
 * @format: prints arguments that are formmated strings
 * @C: Gets the parameter passed.
 * Return: Flags
 */
int get_flags(const char *format, int *C)
{
	int C, Curr_j;
	int Flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (Curr_j = *C + 1; format[Curr_j] != '\0'; Curr_j++)
	{
		for (C = 0; FLAGS_CH[C] != '\0'; C++)
			if (format[Curr_j] == FLAGS_CH[C])
			{
				Flags |= FLAGS_ARR[C];
				break;
			}
		if (FLAGS_CH[C] == 0)
			break;
	}
	*C = Curr_j - 1;

	return (Flags);
}
