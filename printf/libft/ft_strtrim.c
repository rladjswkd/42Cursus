/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:29:16 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 16:29:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*output;
	int		len_output;

	start = -1;
	end = ft_strlen(s1);
	while (s1[++start])
		if (ft_strchr(set, s1[start]) == 0)
			break ;
	while (s1[--end] && start <= end)
		if (ft_strchr(set, s1[end]) == 0)
			break ;
	if (end < start)
		len_output = 1;
	else
		len_output = end - start + 2;
	output = (char *)malloc(sizeof(char) * len_output);
	if (output == 0)
		return (0);
	ft_strlcpy(output, s1 + start, len_output);
	return (output);
}
