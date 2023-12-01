#include "main.h"

/**
 * print_d - prints a number
 * @num: the number to print
 * Return: the length of the number
 */

int print_d(int num)
{
	int i = 0;

	if (num < 0)
	{
		i += _putchar('-');
		if (num == INT_MIN)
		{
			i += _putchar('2');
			num %= 1000000000;
		}

		i += print_d(-num);
	}
	else if (num >= 0 && num <= 9)
		i += _putchar(num + '0');
	else
	{
		i += print_d(num / 10);
		i += print_d(num % 10);
	}
	return (i);
}
