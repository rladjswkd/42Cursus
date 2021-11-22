/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:14:07 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/22 14:14:09 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	i;

	output = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (output == 0)
		return (0);
	i = -1;
	while (s[++i])
		output[i] = (*f)(i, s[i]);
	return (output);
}
