/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:40:52 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 19:30:44 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned int	get_divisor(unsigned int v, unsigned int b)
{
	unsigned int	divisor;

	divisor = 1;
	while (v / divisor > b - 1)
		divisor *= b;
	return (divisor);
}

static int	print(va_list *ap, const char *arr, unsigned int base)
{
	unsigned int	value;
	unsigned int	divisor;
	int				res;

	value = va_arg(*ap, unsigned int);
	divisor = get_divisor(value, base);
	res = 0;
	while (divisor > 0)
	{
		put_char(arr[value / divisor]);
		res++;
		value %= divisor;
		divisor /= base;
	}
	return (res);
}

int	print_hex(va_list *ap, const char **format)
{
	static const char	hexadecimal[2][16] = {
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102},
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}
	};

	return (print(ap, hexadecimal[*((*format)++) == 'X'], 16));
}

int	print_u(va_list *ap, const char **format)
{
	static const char	decimal[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

	(*format)++;
	return (print(ap, decimal, 10));
}
