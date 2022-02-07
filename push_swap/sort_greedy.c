/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/07 20:05:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* b is sorted in decending order */
static unsigned	get_insertion_index(int val, t_stack *b)
{
	unsigned	i;

	i = get_top_index(b) - 1;
	while (++i + 1 < b->size)
		if (val < (b->arr)[i] && (b->arr)[i + 1] < val)
			break ;
	return (i);
}
/* it means the value on stack a's top is not min or max in b, to be called func_normal */
static void	func_normal(t_stack *a, t_stack *b)
{
	unsigned	b_top;
	unsigned	pos;

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
/*
void	sort_greedy(t_stack *a, t_stack *b)
{
	unsigned	a_idx;

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
*/
static int	count_rb(int val, t_stack *b)
{
	unsigned	max_idx;
	unsigned	top_idx;
	int		rb_cnt;

	top_idx = get_top_index(b);
	max_idx = get_max_idx(b);
	if (val > (b->arr)[max_idx] || val < (b->arr)[get_min_idx(b)])
		return (max_idx - top_idx);
	rb_cnt = 0;
	while (top_idx + 1 < b->size)
	{
		rb_cnt++;
		if ((b->arr)[top_idx] > val && val > (b->arr)[top_idx + 1])
			break ;
		top_idx++;
	}
	return (rb_cnt);
}

static t_ops	get_current_ops(t_stack *a, t_stack *b, unsigned a_idx)
{
	t_ops	ops;

	ops.ra = a_idx - get_top_index(a);
	ops.rra = a->size - a_idx;
	ops.rb = count_rb((a->arr)[a_idx], b);
	if (ops.rb == 0)
		ops.rrb = 0;
	else
		ops.rrb = b->size - ops.rb; // rb is the count of elements to be rotated to stack's bottom from top. so, rrb is b->size - ops->rb
	return (ops);
}

static int	get_op_count(t_ops *ops)
{
	int	rr_op;
	int	rrr_op;
	int	cross_op; // (ra, rrb) or (rra, rb)
	int	min;

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
	int	rr_cnt;
	int	i;

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
	int	rrr_cnt;
	int	i;

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
	int	a_cnt;
	int	b_cnt;

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
	b_max_idx = get_max_idx(b);
	if (b_max_idx <= b->size / 2)
		repeat_rotate(b, b_max_idx, 1);
	else
		repeat_rotate(b, b->size - b_max_idx, 0);
	while (b->len)
		print_push(b, a);
}
