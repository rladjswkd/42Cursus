/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:48:37 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 15:58:42 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_rr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned int	rr_cnt;
	unsigned int	i;

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

void	operate_rrr(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned int	rrr_cnt;
	unsigned int	i;

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

void	operate_cross(t_stack *a, t_stack *b, t_ops ops)
{
	unsigned int	a_cnt;
	unsigned int	b_cnt;

	a_cnt = get_min(ops.ra, ops.rra);
	b_cnt = get_min(ops.rb, ops.rrb);
	repeat_rotate(a, a_cnt, a_cnt == ops.ra);
	repeat_rotate(b, b_cnt, b_cnt == ops.rb);
	print_push(a, b);
}
