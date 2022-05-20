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
int i = 0;
int sum = 0;
int (*func)(va_list);
va_list ap;

va_start(ap, format);
if (format[0] == '%' && format[1] == '\0')
return (-1);
while (format != NULL && format[i] != '\0')
{
if (format[i] == '%')
{
if (format[i + 1] == '%')
{
sum += _putchar(format[i]);
i += 2;
}
else
{
func = get_op(format[i + 1]);
if (func)
sum += func(ap);
else
sum = _putchar(format[i]) + _putchar(format[i + 1]);
i += 2;
}
}
else
{
sum += _putchar(format[i]);
i++;
}
}
va_end(ap);
return (sum);
}
return (-1);
}

