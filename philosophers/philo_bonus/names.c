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

char	**access_flag_names(char **initializer)
{
	static char	**names;

	if (initializer)
		names = initializer;
	return (names);
}

char	**access_finish_names(char **initializer)
{
	static char	**names;

	if (initializer)
		names = initializer;
	return (names);
}

char	**access_condition_names(char **initializer)
{
	static char	**names;

	if (initializer)
		names = initializer;
	return (names);
}