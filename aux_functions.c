#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * charac - handles characters %c
 * @c: list with character to print
 * Return: 1 character
 */

int charac(char c)
{
	return (write(1, &c, 1)); /*1=stdout, &c=dire var c, 1=num char*/
}

/**
 * string - handles string %s
 * @str: string to print
 * Return: string
 */

int string(char *str)
{
	int count = 0; /*inicializa count*/
	int i;

	if (str == NULL)
	{
		str =  "(null)";
	}
	for (i = 0; str[i] != '\0'; i++) /*recorre str con i hasta encontrar '\0'*/
	{
		write(1, &str[i], 1); /*1=stdout, str[count]=,1=*/
		count++; /*aumenta el contador despues de cada caracter*/
	}
	return (count); /*retorna el num de char impresos*/
}

/**
 * percent - handles percent %
 * @void: no parameters
 * Return: num of char
 */

int percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_number - Helper function to print an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int j, i = 0;
	int count = 0;
	char buffer[20];
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}


	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}
