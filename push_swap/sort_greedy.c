/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/04 22:44:18 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* b is sorted in decending order */
static uint	get_insertion_index(int val, t_stack *b)
{
	uint	i;

	i = get_top_index(b);
	while (i < b->size)
		if ((b->arr)[i] 
}
/* it means the value on stack a's top is not min or max in b, to be called func_normal */
static void	func_normal(t_stack *a, t_stack *b, uint a_idx, uint b_idx)
{
	if ((b->size) / 2 > 
}

static void	func_min(t_stack *a, t_stack *b)
{
	print_push(a, b);
	print_rotate(b, 1);
}

void	sort_greedy(t_stack *a, t_stack *b)
{
	uint	a_idx;
	uint	b_idx;
	int	b_max;
	int	b_min;

	print_push(a, b);
	while (a->len)
	{
		a_idx = get_top_index(a);
		b_idx = get_top_index(b);
		b_max = find_max(b);
		b_min = find_min(b);
		if ((a->arr)[a_idx] > b_max)
			print_push(a, b);
		else if ((a->arr)[a_idx] < b_min)
			func_min(a, b);
		else
			func_normal(a, b);
	}
}
