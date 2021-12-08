/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:54:14 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 23:13:18 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	if (!(*haystack) && !(*needle))
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	if (len < len_needle)
		return ((char *)0);
	i = -1;
	while (++i <= len - len_needle && haystack[i])
		if (!ft_strncmp(haystack + i, needle, len_needle))
			return ((char *)(haystack + i));
	return (0);
}
