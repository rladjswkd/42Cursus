/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:58:08 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 00:58:10 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	count_words(char const *s)
{
	int	cnt;
	int	start;
	int	end;

	cnt = 0;
	start = 0;
	end = -1;
	while (s[++end])
	{
		if (s[end] == c && start < end)
		{
			start = end + 1;
			cnt++;
		}
	}
	return (cnt + (start != end));
}

static char	**free_assigned(char **output, int to)
{
	int	i;

	i = 0;
	while (i < to)
		free(output[i]);
	free(output);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	*start;
	int		i;

	output = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (output == 0)
		return (0);
	start = s;
	i = 0;
	while (*s)
	{
		if ((*s == c && start < s) || (*s != c && *(s + 1) == 0 && start <= s))
		{
			output[i] = (char *)malloc(sizeof(char) * (s - start + 1));
			if (output[i] == 0)
				return (free_assigned(output, i));
			ft_strlcpy(output[i++], start, s - start + 1);
			start = ++s;
		}
		else
			s++;
	}
	output[i] = 0;
	return (output);
}
