/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:52:33 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 19:10:58 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;

	i = 0;
	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	while (i + 1 < n && s1_temp[i] == s2_temp[i])
		i++;
	return ((unsigned char)s1_temp[i] - (unsigned char)s2_temp[i]);
}
