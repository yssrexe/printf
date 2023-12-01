#include "main.h"

/**
 * _print_hex - function print hex
 * @num: number
 * @heex: base
 * Return: integer
 */
int _print_hex(unsigned long int num, char heex)
{
	int i = 0, y, r, bs;
	char nbr[64], *hex_l = "0123456789abcdef";
	char *hex_u = "0123456789ABCDEF";

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (heex == 'b')
		bs = 2;
	else if (heex == 'o')
		bs = 8;
	else
		bs = 16;
	while (num)
	{
		r = num % bs;
		num = num / bs;
		nbr[i] = r;
		i++;
	}
	y = i - 1;
	while (y >= 0)
	{
		if (heex == 'x')
			_putchar(hex_l[(int)nbr[y]]);
		else if (heex == 'X')
			_putchar(hex_u[(int)nbr[y]]);
		else
			_putchar(nbr[y] + '0');
		y--;
	}
	return (i);
}
/**
 * print_u - function print unsigned numbers
 * @num: number
 * Return: number of bytes
 */

int print_u(unsigned int num)
{
	int i = 0;

	if (num <= 9)
		i += _putchar(num + 48);
	else
	{
		i += print_u(num / 10);
		i += print_u(num % 10);
	}
	return (i);
}

