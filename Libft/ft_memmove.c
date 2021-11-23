/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:41:48 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 19:11:34 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	if (dst == 0 && src == 0)
		return (dst);
	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			dst_char[i] = src_char[i];
	}
	else
	{
		while (len--)
			dst_char[len] = src_char[len];
	}
	return ((void *)dst);
}
