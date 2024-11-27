#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: char string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0; /*count: cuenta los caracteres en total*/
	const char *ptr = format; /*Ptr para recorrer format*/
	va_list args; /*maneja una lista de args variables*/

	if (format == NULL)
		return (-1);
	va_start(args, format); /*Inicializa la lista, utilizando el ultimo arg fijo*/
	for (ptr = format; *ptr != '\0'; ptr++) /*Recorre format hasta '\0'*/
	{
		if (*ptr == '%') /*si ptr es un %*/
		{
			ptr++; /*avanza ptr*/
			if (*ptr == 'c') /*si, ptr es character*/
				count += charac(va_arg(args, int)); /*accede al sig arg, charac imprime c*/
			else if (*ptr == 's') /*si, ptr es string*/
				count += string(va_arg(args, char *)); /*accede arg, fun str imprime*/
			else if (*ptr == '%') /*si, ptr es %*/
				count += percent(); /*imprime %*/
			else
			{
				write(1, "%", 1); /*imprime directamente %*/
				write(1, ptr, 1); /*imprime el caracter desconocido*/
				count += 2; /*al imprimir el % mas el car desconocido, aumenta 2*/
			}
		}
		else
			count += write(1, ptr, 1); /*si no es %, imprime char actual*/
	}
	va_end(args);
	return (count);
}
