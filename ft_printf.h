/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:41:19 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/01/06 14:57:33 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	print_char(int c);
int	print_str(char *s);
int	print_int(long i);
int	print_hex(unsigned long i, const char *base);
int	print_uint(unsigned int i);
int	print_ptr(unsigned long ptr);
int	ft_printf(const char *format, ...);

#endif