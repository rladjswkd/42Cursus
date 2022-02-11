/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:11:18 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/11 19:17:57 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	internal_rotate_both(t_stack *a, t_stack *b, int is_forward)
{
	rotate(a, is_forward);
	rotate(b, is_forward);
}

static void	internal_repeat_rotate(t_stack *s, unsigned count, int flag)
{
	unsigned	i;

	i = 0;
	while (i++ < count)
		rotate(s, flag);
}

void	internal_rr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	rr_cnt;
	unsigned	i;

	rr_cnt = get_min(ops.ra, ops.rb);
	i = 0;
	while (i++ < rr_cnt)
		internal_rotate_both(a, b, 1);
	if (rr_cnt == ops.ra)
		internal_repeat_rotate(b, ops.rb - rr_cnt, 1);
	else
		internal_repeat_rotate(a, ops.ra - rr_cnt, 1);
	push(a, b);
}

void	internal_rrr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	rrr_cnt;
	unsigned	i;

	rrr_cnt = get_min(ops.rra, ops.rrb);
	i = 0;
	while (i++ < rrr_cnt)
		internal_rotate_both(a, b, 0);
	if (rrr_cnt == ops.rra)
		internal_repeat_rotate(b, ops.rrb - rrr_cnt, 0);
	else
		internal_repeat_rotate(a, ops.rra - rrr_cnt, 0);
	push(a, b);
}

void	internal_cross(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	a_cnt;
	unsigned	b_cnt;

	a_cnt = get_min(ops.ra, ops.rra);
	b_cnt = get_min(ops.rb, ops.rrb);
	internal_repeat_rotate(a, a_cnt, a_cnt == ops.ra);
	internal_repeat_rotate(b, b_cnt, b_cnt == ops.rb);
	push(a, b);
}
