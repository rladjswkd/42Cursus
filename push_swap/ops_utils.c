/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:34:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/10 14:33:59 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned	get_min(unsigned x, unsigned y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

unsigned	get_max(unsigned x, unsigned y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
