/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:34:40 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/01/05 13:56:39 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*  
	FLAGS TO HANDLE
	c: char OK
	s: string OK
	p: pointer
	d: integer OK
	i: integer OK
	u: unsigned integer
	x: hexadecimal (lowercase)
	X: hexadecimal (uppercase)
	%: percent character OK
*/

int	print_char(int c)
{
	return (write(1, &c, 1));
}

// TODO: add null str handling
int	print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	print_int(long i)
{
	int		count;
	char	c;

	count = 0;
	if (i < 0)
		return (write(1, &"-", 1) + print_int(-i));
	else if (i >= 10)
		return (print_int(i / 10) + print_int(i % 10));
	else
	{
		c = i + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

// TODO: how to handle negative numbers?
int	print_hex(unsigned long i, const char *base)
{
	int	count;

	count = 0;
	if (i >= 16)
		return (print_hex(i / 16, base) + print_hex(i % 16, base));
	else
		count = write(1, &base[i], 1);
	return (count);
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
	// else if (flag == 'p')
	// 	count = print_ptr(va_arg(args, void *));
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

int	main(void)
{
	int	count;

	void *ptr;

	count = ft_printf("hex: %X\n", -420);
	printf("count: %d\n", count);

	printf("pointer: %X\n", -420);
	return (0);
}
