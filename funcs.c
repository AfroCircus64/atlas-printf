#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char()- prints char to buffer
 * @point: current write pos of buffer
 * @buffer: the buffer
 * @args: args
 *
 * Return: point
 */

int print_char(int point, char *buffer, va_list args)
{
	char c;

	c = va_arg(args, int);
	buffer[point] = (char) c;
	point++;
	return (point);
}

/**
 * print_str()- prints string to buffer
 * @point: current write pos of buffer
 * @buffer: the buffer
 * @args: args
 *
 * Return: point
 */

int print_str(int point, char *buffer, va_list args)
{
	int i;
	char *str;
	char *nullstr;

	str = va_arg(args, char*);
	if (str == NULL)

	{
		nullstr = "(null)";
		i = 0;
		while (nullstr[i] != '\0')
		{
			buffer[point] = nullstr[i];
			i++;
			point++;
		}
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			buffer[point] = str[i];
			i++;
			point++;
		}
	}
	return (point);
}

/**
 * print_d()- prints an int to buffer
 * @point: current write pos of buffer
 * @buffer: the buffer
 * @args: args
 *
 * Return: point (and FREE _iota())
 */

int print_d(int point, char *buffer, va_list args)
{
	char *str;
	int i, d;

	d = va_arg(args, int);
	str = _itoa(d);
	i = 0;
	while (str[i] != '\0')
	{
		buffer[point] = str[i];
		i++;
		point++;
	}
	free(str);
	return (point);
}

/**
 * print_modulo()- prints a modulo character
 * @point: current write pos of buffer
 * @buffer: the buffer
 * @args: args
 *
 * Return: point
 */

int print_modulo(int point, char *buffer, va_list args)
{
	int a;

	a = va_arg(args, int);
	a++;

	buffer[point] = '%';
	point++;
	return (point);
}
