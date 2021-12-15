/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 14:29:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned int	get_divisor(unsigned int value)
{
	unsigned int	divisor;

	divisor = 1;
	while (value / divisor > 15)
		divisor *= 16;
	return (divisor);
}

static int	print_hex(va_list *ap, const char *hexadecimal)
{
	unsigned int	value;
	unsigned int	divisor;
	int				res;

	value = va_arg(*ap, unsigned int);
	divisor = get_divisor(value);
	res = 0;
	while (divisor > 0)
	{
		ft_putchar_fd(hexadecimal[value / divisor], 1);
		res++;
		value %= divisor;
		divisor /= 16;
	}
	return (res);
}

int	print_x(va_list *ap, const char **format)
{
	static const char	hexadecimal[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
			97, 98, 99, 100, 101, 102};

	(*format)++;
	return (print_hex(ap, hexadecimal));
}

int	print_X(va_list *ap, const char **format)
{
	static const char	hexadecimal[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
			65, 66, 67, 68, 69, 70};

	(*format)++;
	return (print_hex(ap, hexadecimal));
}
