/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_long_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 15:50:28 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned long long	get_divisor(unsigned long long v, unsigned int b)
{
	unsigned long long	divisor;

	divisor = 1;
	while (v / divisor > b - 1)
		divisor *= b;
	return (divisor);
}

static int	print(va_list *ap, const char *arr, unsigned int base)
{
	unsigned long long	value;
	unsigned long long	divisor;
	int					res;

	value = va_arg(*ap, unsigned long long);
	divisor = get_divisor(value, base);
	res = 0;
	while (divisor > 0)
	{
		ft_putchar_fd(arr[value / divisor], 1);
		res++;
		value %= divisor;
		divisor /= base;
	}
	return (res);
}

int	print_p(va_list *ap, const char **format)
{
	static const char	hexadecimal[16] = {
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102
	};

	ft_putstr_fd("0x", 1);
	(*format)++;
	return (2 + print(ap, hexadecimal, 16));
}
