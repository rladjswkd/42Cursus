/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:43:39 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/17 21:43:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len_s1 + 1));
	ft_strlcpy(p, s1, len_s1 + 1);
	return (p);
}
