/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:07 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 16:22:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_greedy(t_stack *a, t_stack *b)
{
	t_ops			ops;
	unsigned int	b_max_idx;
	void			(*fp[3])(t_stack *, t_stack *, t_ops);

	fp[0] = &operate_rr;
	fp[1] = &operate_rrr;
	fp[2] = &operate_cross;
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
