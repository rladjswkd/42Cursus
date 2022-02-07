/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:34:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/07 17:35:56 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	get_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
