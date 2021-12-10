/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:58:02 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/10 15:22:18 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (ft_strlen(src));
}

char	*concat_strs(char *dst, char *src)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i_dst;
	size_t	i_src;
	char	*concatenated;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	concatenated = (char *)malloc(sizeof(char) * (len_dst + len_src + 1));
	if (!concatenated)
		return (0);
	i_dst = -1;
	while (++i_dst < len_dst)
		concatenated[i_dst] = dst[i_dst];
	i_src = 0;
	while (i_src < len_src)
		concatenated[i_dst++] = src[i_src++];
	concatenated[i_dst] = 0;
	free(dst);
	return (concatenated);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_output;
	char	*output;

	len_s = ft_strlen(s);
	if (len_s <= start)
		len_output = 0;
	else if (len_s - start < len)
		len_output = len_s - start;
	else
		len_output = len;
	output = (char *)malloc(sizeof(char) * (len_output + 1));
	if (!output)
		return (0);
	ft_strlcpy(output, s + start, len_output + 1);
	return (output);
}
