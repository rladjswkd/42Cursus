/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:19:51 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/17 16:19:52 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	if (src_char + len > dst_char)
	{
		while (len--)
			dst_char[len] = src_char[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			dst_char[i] = src_char[i];
	}
	return ((void *)dst);
}
