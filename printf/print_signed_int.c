/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:40:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 19:23:10 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	get_divisor(int	value)
{
	int	divisor;

	divisor = 1;
	while (value / divisor > 9 || value / divisor < -9)
		divisor *= 10;
	return (divisor);
}

static int	print(int value)
{
	int	res;
	int	divisor;
	int	sign;

	res = 0;
	divisor = get_divisor(value);
	sign = 1 | value >> (sizeof(int) * 8 - 1);
	while (divisor > 0)
	{
		put_char((value / divisor) * sign + 48);
		res++;
		value %= divisor;
		divisor /= 10;
	}
	return (res);
}

static int	print_negative(int value)
{
	put_char('-');
	return (1 + print(value));
}

int	print_di(va_list *ap, const char **format)
{
	static t_ifunc	fp[2] = {print, print_negative};
	int				value;

	value = va_arg(*ap, int);
	(*format)++;
	return ((*fp[value < 0])(value));
}
