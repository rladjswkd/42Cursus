/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:48:23 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/21 23:48:24 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
