/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:09:33 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 19:35:02 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int	res;

	res = 0;
	while (*str)
		res += put_char(*(str++));
	return (res);
}
