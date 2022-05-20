#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 *_printf - recreates printf functions
 *@format: string with format specifiers
 *Return: number of printed chars
 */

int _printf(const char *format, ...)
{
	register short len = 0;
	int (*printFunc)(va_list, mods *);
	mods prefixes = PF_INIT;
	const char *p = format;
	va_list arguments;

	va_start(arguments, format);
	assert(invalidInputs(p));
	for (; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				len += _putchar('%');
				continue;
			}
			while (get_flags(*p, &prefixes))
				p++;
			printFunc = get_print(*p);
			len += (printFunc)
				? printFunc(arguments, &prefixes)
				: _printf("%%%c", *p);
		} else
			len += _putchar(*p);
	}
	_putchar(FLUSH);
	va_end(arguments);
	return (len);
}
