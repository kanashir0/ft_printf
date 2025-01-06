/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:05:33 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/01/06 15:09:31 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (print_str("(null)"));
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

int	print_uint(unsigned int i)
{
	int		count;
	char	c;

	count = 0;
	if (i >= 10)
		return (print_uint(i / 10) + print_uint(i % 10));
	else
	{
		c = i + '0';
		count = write(1, &c, 1);
	}
	return (count);
}

int	print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (print_str("(nil)"));
	else
		return (print_str("0x") + print_hex(ptr, "0123456789abcdef"));
	return (count);
}
