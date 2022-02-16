/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:54:58 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 15:03:42 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *init_stack(int *arr, unsigned size, unsigned len, char name)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (0);
	if (!arr)
	{
		s->arr = (int *)malloc(sizeof (int) * size);
		if (!(s->arr))
			return (0);
	}
	else
		s->arr = arr;
	s->size = size;
	s->len = len;
	s->name = name;
	return (s);
}

int	init_both(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	*arr;

	*a = 0;
	*b = 0;
	arr = get_ints(argc, argv);
	if (!arr)
		exit_on_error(*a, *b);
	*a = init_stack(arr, argc - 1, argc - 1, 'a');
	if (!a)
		exit_on_error(*a, *b);
	*b = init_stack((int *)0, argc - 1, 0, 'b');
	if (!b)
		exit_on_error(*a, *b);
	return (1);
}


