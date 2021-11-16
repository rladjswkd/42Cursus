/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/16 18:57:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	b = (unsigned char *)b;
	while (i < len)
		b[i++] = (unsigned char)c;
	return ((void *)b);
}
