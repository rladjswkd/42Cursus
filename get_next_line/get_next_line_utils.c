/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:49:29 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/04 23:49:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*output;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	output = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!output)
		return (0);
	ft_strlcpy(output, s1, len_s1 + 1);
	ft_strlcpy(output + len_s1, s2, len_s2 + 1);
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
