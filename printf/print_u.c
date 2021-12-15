/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:55:51 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 13:38:22 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned int	get_divisor(unsigned int value)
{
	unsigned int	divisor;

	divisor = 1;
	while (value / divisor > 9)
		divisor *= 10;
	return (divisor);
}

int	print_u(va_list *ap)
{
	unsigned int	value;
	unsigned int	divisor;
	int				res;

	value = va_arg(*ap, unsigned int);
	divisor = get_divisor(value);
	res = 0;
	while (divisor > 0)
	{
		ft_putchar_fd((value / divisor) + 48, 1);
		res++;
		value %= divisor;
		divisor /= 10;
	}
	return (res);
}
