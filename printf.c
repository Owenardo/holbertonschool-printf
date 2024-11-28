#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: char string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr = format;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
				count += charac(va_arg(args, int));
			else if (*ptr == 's')
				count += string(va_arg(args, char *));
			else if (*ptr == '%')
				count += percent();
			else if (*ptr == 'd' || 'i')
				count += print_number(va_arg(args, int));
			else
			{
				write(1, "%", 1);
				write(1, ptr, 1);
				count += 2;
			}
		}
		else
			count += write(1, ptr, 1);
	}
	va_end(args);
	return (count);
}
