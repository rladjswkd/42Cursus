/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:03:08 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/16 19:03:09 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	dst = (unsigned char *)dst;
	src = (unsigned char *)src;
	if (src + len >= dst)
	{
		while (len--)
			dst[len] = src[len]
	}
	else
	{
		i = -1;
		while (++i < len)
			dst[i] = src[i];
	}
	return ((void *)dst)
}

