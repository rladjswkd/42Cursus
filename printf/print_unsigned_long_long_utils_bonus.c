/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_long_long_utils_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:19:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:37:19 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static unsigned long long	get_divisor(unsigned long long v, unsigned int b)
{
	unsigned long long	divisor;

	divisor = 1;
	while (v / divisor > b - 1)
		divisor *= b;
	return (divisor);
}

void	get_str_ull(va_list *ap, char *str, const char *arr, int base)
{
	unsigned long long	value;
	unsigned long long	divisor;
	int					i;

	value = va_arg(*ap, unsigned long long);
	divisor = get_divisor(value, base);
	i = 0;
	while (divisor > 0)
	{
		str[i++] = arr[value / divisor];
		value %= divisor;
		divisor /= base;
	}
	str[i] = '\0';
}
