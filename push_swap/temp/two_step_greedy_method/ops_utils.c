/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:34:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/11 19:16:15 by gyepark          ###   ########.fr       */
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
	t_ops		ops;
	unsigned	rr_op;
	unsigned	rrr_op;
	unsigned	cross_op; // (ra, rrb) or (rra, rb)

	ops.ra = a_idx - get_top_index(a);
	ops.rra = (a->len - ops.ra) % a->len;
	ops.rb = count_rb((a->arr)[a_idx], b);
	ops.rrb = (b->len - ops.rb) % b->len;
	rr_op = get_max(ops.ra, ops.rb);
	rrr_op = get_max(ops.rra, ops.rrb);
	cross_op = get_min(ops.ra + ops.rrb, ops.rra + ops.rb);
	ops.cnt = get_min(get_min(rr_op, rrr_op), cross_op);
	if (ops.cnt == rr_op)
		ops.op_type = 0;
	else if (ops.cnt == rrr_op)
		ops.op_type = 1;
	else
		ops.op_type = 2;
	return (ops);
}

static void	get_next_stack(t_stack *s)
{
	unsigned	i;
	int		*temp_swap;

	i = 0;
	while (i < s->size)
	{
		(s->temp_arr)[i] = (s->arr)[i];
		i++;
	}
	temp_swap = s->arr;
	s->arr = s->temp_arr;
	s->temp_arr = temp_swap;
}

static unsigned	get_next_count(t_stack a, t_stack b, t_ops ops)
{
	void	(*fp[3])(t_stack *, t_stack *, t_ops) = {internal_rr, internal_rrr, internal_cross};
	t_ops	next;
	int	*temp_swap;

	get_next_stack(&a);
	get_next_stack(&b);
	(*fp[ops.op_type])(&a, &b, ops);
	next = get_optimal_ops(&a, &b, 1);
	temp_swap = a.arr;
	a.arr = a.temp_arr;
	a.temp_arr = temp_swap;
	temp_swap = b.arr;
	b.arr = b.temp_arr;
	b.temp_arr = temp_swap;
	return (next.cnt);
}

t_ops	get_optimal_ops(t_stack *a, t_stack *b, int step)
{
	unsigned	a_idx;
	t_ops		cur;
	t_ops		opt;
	unsigned	cur_next;
	unsigned	opt_next;

	a_idx = get_top_index(a);
	opt = get_current_ops(a, b, a_idx);
	if (!step && a->len > 1)
		opt_next = get_next_count(*a, *b, opt);
	while (++a_idx < a->size)
	{
		cur = get_current_ops(a, b, a_idx);
		if (!step)
			cur_next = get_next_count(*a, *b, cur);
		if (!step && cur.cnt + cur_next < opt.cnt + opt_next)
		{
			opt = cur;
			opt_next = cur_next;
		}
		else if (step && cur.cnt < opt.cnt)
			opt = cur;
	}
	return (opt);
}
