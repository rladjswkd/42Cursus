/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:09:33 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:35:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str, int len)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && i < len)
		res += put_char(str[i++]);
	return (res);
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
