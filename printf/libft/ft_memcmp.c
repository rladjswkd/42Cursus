/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:52:33 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 22:03:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;

	i = -1;
	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	while (++i < n)
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
	return (0);
}
