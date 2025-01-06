/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:34:40 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/01/06 15:09:42 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	handle_format(char flag, va_list args)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count = print_char(va_arg(args, int));
	else if (flag == 's')
		count = print_str(va_arg(args, char *));
	else if (flag == 'd' || flag == 'i')
		count = print_int(va_arg(args, int));
	else if (flag == '%')
		count = print_char(flag);
	else if (flag == 'x')
		count = print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		count = print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (flag == 'u')
		count = print_uint(va_arg(args, unsigned int));
	else if (flag == 'p')
		count = print_ptr(va_arg(args, unsigned long));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += handle_format(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
