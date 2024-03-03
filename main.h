#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

typedef struct op
{
	char *op;
	int (*f)(int buffpoint, char *buffer, va_list copy_args);
} op_t;

int _printf(const char *format, ...);

int (*get_op_func(char c))(int, char*, va_list);
int print_char(int point, char* buffer, va_list);
int print_str(int point, char* buffer, va_list);
int print_d(int point, char* buffer, va_list);
int print_37(void);
int print_modulo(int point, char* buffer);

int _strlen(char *str);
char* _itoa(int num);
int _putchar(char *c);

#endif
