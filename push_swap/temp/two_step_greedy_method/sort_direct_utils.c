/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_direct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:30:51 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/11 13:02:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_smallest(t_stack *a, t_stack *b)
{
	unsigned	ra;
	unsigned	rra;

	ra = get_min_index(a) - get_top_index(a);
	rra = (a->len - ra) % a->len;
	if (ra < rra)
		repeat_rotate(a, ra, 1);
	else
		repeat_rotate(a, rra, 0);
	print_push(a, b);
}
