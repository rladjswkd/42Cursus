/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:34:20 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 20:19:37 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static unsigned int	get_divisor(unsigned int v, unsigned int b)
{
	unsigned long long	divisor;

	divisor = 1;
	while (v / divisor > b - 1)
		divisor *= b;
	return (divisor);
}

void	get_str_ui(va_list *ap, char *str, const char *arr, int base)
{
	unsigned int	value;
	unsigned int	divisor;
	int				i;

	value = va_arg(*ap, unsigned int);
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
