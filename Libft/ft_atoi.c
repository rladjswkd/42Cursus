/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:17:57 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/26 16:40:22 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_atoi(const char *str)
{
	int					sign;
	int					result;
	unsigned long long	checker;

	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{ 
		if (*str == '-')
			sign = -1;
		str++;
	}	
	result = 0;
	checker = 0;
	while (ft_isdigit(*str))
	{
		result = 10 * result + sign * (*str - 48);
		checker = 10 * checker + (*str - 48);
		if (sign == -1 && checker >= 9223372036854775808ULL)
			return (0);
		if (sign == 1 && checker >= 9223372036854775807ULL)
			return (-1);
		str++;
	}
	return (result);
}
