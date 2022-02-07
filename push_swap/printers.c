/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:15:17 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/07 19:54:28 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_name(t_stack *s)
{
	write(1, &(s->name), 1);
	write(1, "\n", 1);
}

void	print_swap(t_stack *s)
{
	swap(s);
	write(1, "s", 1);
	print_name(s);
}

void	print_push(t_stack *from, t_stack *to)
{
	push(from, to);
	write(1, "p", 1);
	print_name(to);
}

void	print_rotate(t_stack *s, int is_forward)
{
	rotate(s, is_forward);
	if (is_forward)
		write(1, "r", 1);
	else
		write(1, "rr", 2);
	print_name(s);
}

void	print_rotate_both(t_stack *a, t_stack *b, int is_forward)
{
	rotate(a, is_forward);
	rotate(b, is_forward);
	if (is_forward)
		write(1, "rr\n", 3);
	else
		write(1, "rrr\n", 4);
}
