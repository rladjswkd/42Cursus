/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:54:14 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 21:30:12 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		len_needle;

	if (!(*haystack) && !(*needle))
		return ((char *)haystack);
	i = -1;
	len_needle = ft_strlen(needle);
	while (++i + len_needle < len + 1)
		if (!ft_strncmp(haystack + i, needle, len_needle))
			return ((char *)(haystack + i));
	return (0);
}
