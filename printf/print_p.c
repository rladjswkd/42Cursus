/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:42 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 12:48:31 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned long long	get_divisior(unsigned long long value)
{
	unsigned long long	divisor;
	
	divisor = 1;
	while (value / divisor > 15)
		divisor *= 16;
	return (divisor);
}

int	print_p(va_list *ap)
{
	unsigned long long	value;
	unsigned long long	divisor;
	static char			hexadecimal[16] = {48, 49, 50, 51, 52, 53, 54, 55, 56,
		57, 97, 98, 99, 100, 101, 102};
	int					res;


	value = va_arg(*ap, unsigned long long);
	divisor = get_divisior(value);
	ft_putstr_fd("0x", 1);
	res = 2;
	while (divisor > 0)
	{
		ft_putchar_fd(hexadecimal[value / divisor], 1);
		res++;
		value %= divisor;
		divisor /= 16;
	}
	return (res);
}
