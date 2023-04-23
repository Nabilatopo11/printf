#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/**
 *my_vprintf - work as vprintf() function
 *@ap: list
 *@format: char
 *Return: len
*/
int my_vprintf(const char *format, va_list ap)
{
	int len = 0;
	const char *p = format;
	char *s;
	int d;
	unsigned int i;
	char c;
	while (*p)
	{
		if (*p != '%')
		{
			putchar(*p++);
			len++;
			continue;
		}
		switch (*++p)
		{
			case 's':
				s = va_arg(ap, char *);
				printf("%s", s);
				len += strlen(s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("%d", d);
				len += sizeof(int);
				break;
			case 'i':
				i = va_arg(ap, unsigned int);
				printf("%d", d);
				len += sizeof(unsigned int);
				break;
			case 'u':
				i = va_arg(ap, unsigned int);
				printf("%u", i);
				len += sizeof(unsigned int);
				break;
			case 'o':
				i = va_arg(ap, unsigned int);
				printf("%o", i);
				len += sizeof(unsigned int);
				break;
			case 'X':
				i = va_arg(ap, unsigned int);
				printf("%X", i);
				len += sizeof(unsigned int);
				break;
			case 'x':
				i = va_arg(ap, unsigned int);
				printf("%x", i);
				len += sizeof(unsigned int);
				break;
			case 'c':
				c = va_arg(ap, int);
				putchar(c);
				len++;
				break;
			case '%':
				putchar('%');
				len++;
				break;
			case 'p':
				i = va_arg(ap, unsigned int);
				printf("%p", i);
				len += sizeof(unsigned int);
				break;
			default:
				putchar(*p++);
				len++;
		}
		p++;
	}
	return (len);
}
/**
 *_printf - work as printf() function
 *@format: format specifiers
 *Return: len
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int len;

	va_start(ap, format);
	len = my_vprintf(format, ap);
	va_end(ap);
	return (len);
}
