/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:41:48 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/29 14:02:42 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (dst == 0 && src == 0)
		return (dst);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			dst_temp[i] = src_temp[i];
	}
	else
	{
		while (len--)
			dst_temp[len] = src_temp[len];
	}
	return ((void *)dst);
}
