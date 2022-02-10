/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:34:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/10 18:44:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned	count_rb(int val, t_stack *b)
{
	unsigned	max_idx;
	unsigned	top_idx;
	unsigned	rb_cnt;

	top_idx = get_top_index(b);
	max_idx = get_max_index(b);
	if (val > (b->arr)[max_idx] || val < (b->arr)[get_min_index(b)])
		return (max_idx - top_idx);
	rb_cnt = 0;
	while (++top_idx < b->size)
	{
		rb_cnt++;
		if ((b->arr)[top_idx - 1] > val && val > (b->arr)[top_idx])
			return (rb_cnt);
	}
	return (0);
}

t_ops	get_current_ops(t_stack *a, t_stack *b, unsigned a_idx)
{
	t_ops	ops;

	ops.ra = a_idx - get_top_index(a);
	ops.rra = (a->len - ops.ra) % a->len;
	ops.rb = count_rb((a->arr)[a_idx], b);
	ops.rrb = (b->len - ops.rb) % b->len;
	return (ops);
}

unsigned	get_op_count(t_ops *ops)
{
	unsigned	rr_op;
	unsigned	rrr_op;
	unsigned	cross_op; // (ra, rrb) or (rra, rb)
	unsigned	min;

	rr_op = get_max(ops->ra, ops->rb);
	rrr_op = get_max(ops->rra, ops->rrb);
	cross_op = get_min(ops->ra + ops->rrb, ops->rra + ops->rb);
	min = get_min(get_min(rr_op, rrr_op), cross_op);
	if (min == rr_op)
		ops->op_type = 0;
	else if (min == rrr_op)
		ops->op_type = 1;
	else
		ops->op_type = 2;
	return (min);
}

t_ops	get_optimal_ops(t_stack *a, t_stack *b)
{
	unsigned	a_idx;
	t_ops		current;
	t_ops		optimal;

	a_idx = get_top_index(a);
	optimal = get_current_ops(a, b, a_idx);
	get_op_count(&optimal);
	while (++a_idx < a->size)
	{
		current = get_current_ops(a, b, a_idx);
		if (get_op_count(&current) < get_op_count(&optimal))
			optimal = current;
	}
	return (optimal);
}
