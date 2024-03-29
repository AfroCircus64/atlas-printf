#include "main.h"
#include <stdarg.h>
/**
 * _printf - main print fucntion
 * @format: character string
 * @...: variable number of parameters
 * Return: printf
 */

int _printf(const char *format, ...)
{
	va_list args;
	char op;
	char buffer[1024];
	int buffpoint, formatpoint;

	va_start(args, format);

	op = 'a';
	buffpoint = 0;
	formatpoint = 0;
	while (format[formatpoint] != '\0')
	{
		if (format[formatpoint] != '%')
		{
			buffer[buffpoint] = format[formatpoint];
			formatpoint++;
			buffpoint++;
		}
		else
		{
			op = (format[formatpoint + 1]);
			buffpoint = get_op_func(op)(buffpoint, buffer, args);
			formatpoint = formatpoint + 2;
		}
	}

	buffer[buffpoint] = '\0';
	buffpoint = 0;
	while (buffer[buffpoint] != '\0')
	{
		_putchar(&buffer[buffpoint]);
		buffpoint++;
	}
	va_end(args);
	return (_strlen(buffer));
}
