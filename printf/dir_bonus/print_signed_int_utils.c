/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:48:39 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 19:26:00 by gyepark          ###   ########.fr       */
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

void	get_str(va_list *ap, char *str, t_conv *conv)
{
	int	value;
	int	divisor;
	int	sign;
	int	i;

	value = va_arg(*ap, int);
	divisor = get_divisor(value);
	sign = (1 & value >> (sizeof(int) * 8 - 1)) * -2 + 1;
	i = 0;
	while (divisor > 0)
	{
		str[i++] = (value / divisor) * sign + 48;
		value %= divisor;
		divisor /= 10;
	}
	str[i] = '\0';
	conv->spec |= (sign < 0) << MINUS;
}
