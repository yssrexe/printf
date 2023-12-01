#include "main.h"

/**
 * spec_string - handle non printable chars
 * @str: string
 * Return: number of bytes
 */

int spec_string(char *str)
{
	int i = 0;
	int length = 0;

	if (!str)
		return (print_s("(null)"));

	while (str[i])
	{
		if (_printable(str[i]))
		{
			_putchar(str[i]);
			length++;
		}
		else
		{
			length += print_s("\\x");
			if (str[i] <= 15)
				length += _putchar('0');
			length += _print_hex(str[i], 'X');
		}
		i++;
	}
	return (length);
}


/**
 * _printable - check if char is printable
 * @c: char
 * Return: -1 or c
 */

int _printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}
