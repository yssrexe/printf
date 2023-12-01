#include "main.h"

/**
 * print_s - prints a string
 * @str: the string to print
 * Return: the length of the string
 */

int print_s(char *str)
{
	int i, len = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		len += _putchar(str[i]);
	}
	return (len);
}

