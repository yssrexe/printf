#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * @...: arguments list
 *
 * Return: the number of characters printed, or -1 if an error occurred
 */
int _printf(const char *format, ...)

{
	va_list(args);
	int len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);
	len = print_handler(format, args);
	va_end(args);
	return (len);
}

/**
 * print_handler - Entry point
 * @format: format
 * @args: args
 * Return: length
 */

int print_handler(const char *format, va_list args)
{
	int i, len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			len += handle_format(format[i], args);
		}
		else
		{
			len += _putchar(format[i]);
		}
	}
	return (len);
}

/**
 * handle_format - entry point
 * @format: format
 * @args: args
 * Return: Result
*/
int handle_format(char format, va_list args)
{
	switch (format)
	{
		case 'c':
			return (_putchar(va_arg(args, int)));
		case 's':
			return (print_s(va_arg(args, char *)));
		case '%':
			return (_putchar('%'));
		case 'd':
		case 'i':
			return (print_d(va_arg(args, int)));
		case 'b':
			return (_print_hex(va_arg(args, unsigned int), format));
		case 'o':
			return (_print_hex(va_arg(args, unsigned int), format));
		case 'x':
			return (_print_hex(va_arg(args, unsigned int), format));
		case 'X':
			return (_print_hex(va_arg(args, unsigned int), format));
		case 'u':
			return (print_u(va_arg(args, unsigned int)));
		case 'S':
			return (spec_string(va_arg(args, char *)));
		default:
			return (handle_unknown_format(format));
	}
}

/**
 * handle_unknown_format - Handle unknown format specifiers here
 * @format: format
 * Return: Result
*/

int handle_unknown_format(char format)
{
	return (_putchar('%') + _putchar(format));
}

