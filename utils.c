#include "main.h"
/**
 * is_printable - function checks a  char is printable or not
 * @c: Character to be evaluated.
 * Return: 1 for  printable, else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buff: Array of characters
 * @i: Index at which to start appending.
 * @askey_code: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char askey_code, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (askey_code < 0)
		askey_code *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[askey_code / 16];
	buff[i] = map_to[askey_code % 16];

	return (3);
}

/**
 * is_digit - function checks if a char is a digit
 * @c: Character to be evaluated
 *
 * Return: 1 for  digit, else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number -a  function converts a number to the specified size
 * @numb: Number to be convered.
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */

long int convert_size_number(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_size_unsgnd - Conver a number to the specified size
 * @numb: Number to be converted
 * @size: Number indicating the type to be converted
 * Return: Casted value of num
 */

long int convert_size_unsgnd(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
