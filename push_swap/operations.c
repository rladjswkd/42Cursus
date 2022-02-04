/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:12:05 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/04 18:13:54 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	temp;
	int	top;

	if (s->len < 2)
		return ;
	top = s->size - s->len;
	temp = (s->arr)[top];
	(s->arr)[top] = (s->arr)[top + 1];
	(s->arr)[top + 1] = temp;
}

void	push(t_stack *from, t_stack *to)
{
	if (!(from->len))
		return ;
	(to->arr)[to->size - (to->len)++ - 1] =
		(from->arr)[from->size - (from->len)--];
}

void	rotate(t_stack *s, int is_forward)
{
	int	i;
	int	temp;

	if (is_forward)
	{
		i = s->size - s->len;
		temp = (s->arr)[i];
		while (++i < s->size)
			(s->arr)[i - 1] = (s->arr)[i];
		(s->arr)[s->size - 1] = temp;
	}
	else
	{
		i = s->size - 1;
		temp = (s->arr)[i];
		while (--i >= s->size - s->len)
			(s->arr)[i + 1] = (s->arr)[i];
		(s->arr)[s->size - s->len] = temp;
	}
}
