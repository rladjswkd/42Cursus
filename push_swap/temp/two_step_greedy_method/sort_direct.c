/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_direct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:23:32 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/11 13:03:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *s)
{
	if ((s->arr)[0] > (s->arr)[1])
		print_swap(s);
}

static void	sort_three(t_stack *s)
{
	if (is_sorted(s))
		return ;
	if (get_top_index(s) == get_min_index(s))
	{
		print_rotate(s, 0);
		print_swap(s);
	}
	else if (get_top_index(s) == get_max_index(s))
	{
		print_rotate(s, 1);
		if (get_top_index(s) != get_min_index(s))
			print_swap(s);
	}
	else
	{
		if (s->size - 1 == get_max_index(s))
			print_swap(s);
		else
			print_rotate(s, 0);
	}
}

static void	sort_four(t_stack *a, t_stack *b)
{
	move_smallest(a, b);
	sort_three(a);
	print_push(b, a);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	move_smallest(a, b);
	sort_four(a, b);
	print_push(b, a);
}

void	sort_direct(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		return ;
}
