/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:45:11 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 15:58:19 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_min(unsigned int x, unsigned int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

unsigned int	get_max(unsigned int x, unsigned int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
