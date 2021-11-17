/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:18:18 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/17 16:18:19 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;

	i = 0;
	s_temp = (unsigned char *)s;
	while (i < n)
		s_temp[i++] = 0;
}
