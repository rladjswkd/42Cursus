/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:12:15 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 14:55:28 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  ft_strlen(char *s)
{
        int  len;

        len = 0;
        while (s[len])
                len++;
        return (len);
}

static int  ft_strlcpy(char *dst, char *src, int dstsize)
{
        int  i;

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

char    *ft_substr(char *s, int start, int len)
{
        int  len_s;
        int  len_output;
        char    *output;

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

char    *ft_strjoin(char *s1, char *s2)
{
        int             len_s1;
        int             len_s2;
        char    *output;

        len_s1 = ft_strlen(s1);
        len_s2 = ft_strlen(s2);
        output = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
        if (!output)
                return (0);
        ft_strlcpy(output, s1, len_s1 + 1);
        ft_strlcpy(output + len_s1, s2, len_s2 + 1);
        return (output);
}

int	are_same_strings(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
