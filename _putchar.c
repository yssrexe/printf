#include "main.h"

/**
 * _putchar - function print c
 * @c: character
 * Return: 1 or 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

