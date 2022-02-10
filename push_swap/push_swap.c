/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/10 18:10:24 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* todo */
/* 1. change the code to accept command line arguments like "1 2 3" 4 5 */
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

static int	init_both(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	*arr;

	arr = get_ints(argc, argv);
	if (!arr)
		return (0);
	*a = init_stack(arr, argc - 1, argc - 1, 'a');
	if (!a)
		return (0);
	*b = init_stack((int *)0, argc - 1, 0, 'b');
	if (!b)
		return (0);
	return (1);
}

static void	free_both(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	/* do todo 1. here and update argc, argv to represent newly created int list */
	if (!init_both(&a, &b, argc, argv) || is_sorted(a))
		return (0);
	/* sort */
	if (a->size > 3)
		sort_greedy(a, b);
	else
		sort_direct(a, b);
	free_both(a, b);
	return (0);
}
