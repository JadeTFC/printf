#include "main.h"

/**
 * print_flag - finds the flag functions
 * @s: the format string
 * @func: the functions struct
 * Return: 1 if flag was valid, 0 if otherwise.
 */

int print_flag(char *s, func_t *func)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = func->plus = 1;
			break;
		case ' ':
			i = func->space = 1;
			break;
		case '#':
			i = func->hashtag = 1;
			break;
		case '-':
			i = func->minus = 1;
			break;
		case '0':
			i = func->zero = 1;
			break;
	}
	return (i);
}

/**
 * print_modifier - finds the modifier function
 * @s: string for format
 * @func: function structure
 * Return: if modifier was valid
 */

int print_modifier(char *s, func_t *func)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = func->h = 1;
			break;
		case 'l':
			i = func->l = 1;
			break;
	}
	return (i);
}

/**
 * print_width - gets the width from the format string
 * @s: the format string
 * @func: the function struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *print_width(char *s, func_t *func, va_list ap)

	/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	func->width = d;
	return (s);
}
