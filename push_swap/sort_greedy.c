/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/10 17:30:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static unsigned	count_rb(int val, t_stack *b)
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

static t_ops	get_current_ops(t_stack *a, t_stack *b, unsigned a_idx)
{
	t_ops	ops;

	ops.ra = a_idx - get_top_index(a);
	ops.rra = (a->len - ops.ra) % a->len;
	ops.rb = count_rb((a->arr)[a_idx], b);
	ops.rrb = (b->len - ops.rb) % b->len;
	return (ops);
}

static unsigned	get_op_count(t_ops *ops)
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

static t_ops	get_optimal_ops(t_stack *a, t_stack *b)
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

static void	operate_rr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	rr_cnt;
	unsigned	i;

	rr_cnt = get_min(ops.ra, ops.rb);
	i = 0;
	while (i++ < rr_cnt)
		print_rotate_both(a, b, 1);
	if (rr_cnt == ops.ra)
		repeat_rotate(b, ops.rb - rr_cnt, 1);
	else
		repeat_rotate(a, ops.ra - rr_cnt, 1);
	print_push(a, b);
}

static void	operate_rrr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	rrr_cnt;
	unsigned	i;

	rrr_cnt = get_min(ops.rra, ops.rrb);
	i = 0;
	while (i++ < rrr_cnt)
		print_rotate_both(a, b, 0);
	if (rrr_cnt == ops.rra)
		repeat_rotate(b, ops.rrb - rrr_cnt, 0);
	else
		repeat_rotate(a, ops.rra - rrr_cnt, 0);
	print_push(a, b);
}

static void	operate_cross(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned	a_cnt;
	unsigned	b_cnt;

	a_cnt = get_min(ops.ra, ops.rra);
	b_cnt = get_min(ops.rb, ops.rrb);
	repeat_rotate(a, a_cnt, a_cnt == ops.ra);
	repeat_rotate(b, b_cnt, b_cnt == ops.rb);
	print_push(a, b);
}

void	sort_greedy(t_stack *a, t_stack *b)
{
	t_ops		ops;
	unsigned	b_max_idx;
	void		(*fp[3])(t_stack *, t_stack *, t_ops) = {operate_rr, operate_rrr, operate_cross};

	print_push(a, b);
	while (a->len)
	{
		ops = get_optimal_ops(a, b);
		(*fp[ops.op_type])(a, b, ops);
	}
	b_max_idx = get_max_index(b);
	if (b_max_idx <= b->size / 2)
		repeat_rotate(b, b_max_idx, 1);
	else
		repeat_rotate(b, b->size - b_max_idx, 0);
	while (b->len)
		print_push(b, a);
}
