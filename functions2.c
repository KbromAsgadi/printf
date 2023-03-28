#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @Buffer: A Buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed.
 */

int print_pointer(va_list types, char Buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; 
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	Buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		Buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(Buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii codes IN hexa of non printable chars
 * @types: Lists of arguments
 * @Buffer: A Buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The numbers of chars printed
 */

int print_non_printable(va_list types, char Buffer[],
	int flags, int width, int precision, int size)
{
	int C = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[C] != '\0')
	{
		if (is_printable(str[C]))
			Buffer[C + offset] = str[C];
		else
			offset += append_hexa_code(str[C], Buffer, C + offset);

		C++;
	}

	Buffer[C + offset] = '\0';

	return (write(1, Buffer, C + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lists of arguments
 * @Buffer: A Buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char Buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int C, count = 0;

	UNUSED(Buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (C = 0; str[C]; C++)
		;

	for (C = C - 1; C >= 0; C--)
	{
		char z = str[C];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string IN rot13.
 * @types: Lists of arguments
 * @Buffer: A Buffer array that handles a print
 * @flags:  Calculates flags that are active
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char Buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int C, D;
	int count = 0;
	char IN[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char OUT[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(Buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (C = 0; str[C]; C++)
	{
		for (D = 0; IN[D]; D++)
		{
			if (IN[D] == str[C])
			{
				y = OUT[D];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!IN[D])
		{
			y = str[C];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}

