/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:11:09 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/04 18:54:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint	get_top_index(t_stack *s)
{
	return (((unsigned int)s->size - (unsigned int)s->len));
}

int	find_max(t_stack *s)
{
	int	i;
	int	max;

	i = get_top_index(s);
	max = (s->arr)[i];
	while (++i < s->size)
		if (max < (s->arr)[i])
			max = (s->arr)[i];
	return (max);
}

int	find_min(t_stack *s)
{
	int	i;
	int	min;

	i = get_top_index(s);
	min = (s->arr)[i];
	while (++i < s->size)
		if (min > (s->arr)[i])
			min = (s->arr)[i];
	return (min);
}


