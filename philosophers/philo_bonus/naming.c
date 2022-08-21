/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:13:02 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/21 12:13:02 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "constants.h"

int	get_sem_name(int i, const char *base, int len, char **name)
{
	int		temp;
	char	*res;

	temp = i;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (i)
	{
		res[--len] = i % 10 + 48;
		i /= 10;
	}
	while (--len > -1)
		res[len] = base[len];
	*name = res;
	return (1);
}
