/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:11:56 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 21:11:57 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	get_size(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		temp;
	char	*output;

	if (n == 0)
		len = 1;
	else
		len = (n < 0) + get_size(n);
	sign = 1 + (-2 * (n < 0));
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == 0)
		return (0);
	output[len--] = 0;
	temp = n;
	while (temp != 0)
	{
		output[len--] = sign * (temp % 10) + 48;
		temp /= 10;
	}
	if (n == 0)
		output[len] = 48;
	else if (sign < 0)
		output[len] = '-';
	return (output);
}
