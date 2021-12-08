/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:52:47 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/17 19:52:48 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_temp;

	i = -1;
	s_temp = (const unsigned char *)s;
	while (++i < n)
		if (s_temp[i] == (unsigned char)c)
			return ((void *)(s_temp + i));
	return (0);
}	
