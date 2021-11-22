/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:40:55 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 20:40:57 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (dst == 0 && src == 0)
		return (0);
	i = -1;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (++i < n)
		dst_temp[i] = src_temp[i];
	return ((void *)dst);
}
