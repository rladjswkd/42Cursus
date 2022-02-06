/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/06 15:42:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* b is sorted in decending order */
static uint	get_insertion_index(int val, t_stack *b)
{
	uint	i;

	i = get_top_index(b);
	while (i + 1 < b->size)
		if (val < (b->arr)[i] && (b->arr)[i + 1] < val)
			break ;
	return (i);
}
/* it means the value on stack a's top is not min or max in b, to be called func_normal */
static void	func_normal(t_stack *a, t_stack *b)
{
	uint	b_top;
	uint	pos;

	b_top = get_top_index(b);
	pos = get_insertion_index((a->arr)[get_top_index(a)], b);
	if ((b_top + b->size) / 2 < pos)
	{
		repeat_rotate(b, pos - b_top + 1, 1);
		print_push(a, b);
		repeat_rotate(b, pos - b_top + 1, 0);
	}
	else
	{
		repeat_rotate(b, b->size - pos - 1, 0);
		print_push(a, b);
		repeat_rotate(b, b->size - pos, 1);
	}
}

static void	func_min(t_stack *a, t_stack *b)
{
	print_push(a, b);
	print_rotate(b, 1);
}

void	sort_greedy(t_stack *a, t_stack *b)
{
	uint	a_idx;

	print_push(a, b);
	while (a->len)
	{
		a_idx = get_top_index(a);
		if ((a->arr)[a_idx] > (b->arr)[get_top_index(b)])
			print_push(a, b);
		else if ((a->arr)[a_idx] < (b->arr)[b->size - 1])
			func_min(a, b);
		else
			func_normal(a, b);
	}
	while (b->len)
		print_push(b, a);
}
