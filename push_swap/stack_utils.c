/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:11:09 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:01 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
unsigned int	get_max_index(t_stack *s)
{
	unsigned int	i;
	unsigned int	idx;

	i = get_top_index(s);
	idx = i;
	while (++i < s->size)
		if ((s->arr)[idx] < (s->arr)[i])
			idx = i;
	return (idx);
}

unsigned int	get_min_index(t_stack *s)
{
	unsigned int	i;
	unsigned int	idx;

	i = get_top_index(s);
	idx = i;
	while (++i < s->size)
		if ((s->arr)[idx] > (s->arr)[i])
			idx = i;
	return (idx);
}

int	is_sorted(t_stack *s)
{
	unsigned int	i;

	i = get_top_index(s);
	while (i + 1 < s->size)
	{
		if ((s->arr)[i] > (s->arr)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	repeat_rotate(t_stack *s, int count, int is_forward)
{
	int	i;

	i = -1;
	while (++i < count)
		print_rotate(s, is_forward);
}

unsigned int	get_top_index(t_stack *s)
{
	return (((unsigned int)s->size - (unsigned int)s->len));
}
