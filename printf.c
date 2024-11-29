#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: char string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);
			if (*ptr == 'c')
				count += charac(va_arg(args, int));
			else if (*ptr == 's')
				count += string(va_arg(args, char *));
			else if (*ptr == '%')
				count += write(1, "%", 1);
			else if (*ptr == 'd' || *ptr == 'i')
				count += print_number(va_arg(args, int));
			else
			{
				count += write(1, "%", 1);
				count += write(1, ptr, 1);
			}
		}
		else
			count += write(1, ptr, 1);
	}
	va_end(args);
	return (count);
}
