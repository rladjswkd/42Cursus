/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:31:55 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/28 14:22:59 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	count_words(char const *s, char c)
{
	int	cnt;
	int	start;
	int	end;

	cnt = 0;
	start = 0;
	end = -1;
	while (s[++end])
	{
		if (s[end] == c)
		{
			if (start < end)
				cnt++;
			start = end + 1;
		}
	}
	return (cnt + (start != end));
}

static char	**free_assigned(char **output, int to)
{
	int	i;

	i = 0;
	while (i < to)
		free(output[i++]);
	free(output);
	return (0);
}

static int	get_size(char const *start, char const *s, char c)
{
	if (*s == c && start < s)
		return (s - start + 1);
	else
		return (s - start + 2);
}

static char	**do_split(char **output, char const *s, char c)
{
	const char	*start;
	int			i;

	start = s;
	i = 0;
	while (*s)
	{
		if ((*s == c && start < s) || (*s != c && *(s + 1) == 0 && start <= s))
		{
			output[i] = (char *)malloc(sizeof(char) * get_size(start, s, c));
			if (output[i] == 0)
				return (free_assigned(output, i));
			ft_strlcpy(output[i++], start, get_size(start, s, c));
			start = ++s;
		}
		else if (*s == c)
			start = ++s;
		else
			s++;
	}
	output[i] = 0;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char		**output;

	output = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (output == 0)
		return (0);
	return (do_split(output, s, c));
}
