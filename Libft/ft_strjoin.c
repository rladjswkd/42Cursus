/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:29:49 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 16:29:50 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
