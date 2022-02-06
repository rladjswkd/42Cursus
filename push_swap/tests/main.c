/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/06 15:21:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* todo */
/* 1. change the code to accept command line arguments like "1 2 3" 4 5 */

#include "push_swap.h"

static void	init_both(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*a)->arr = get_ints(argc, argv);
	(*a)->size = argc - 1;
	(*a)->len = (*a)->size;
	(*a)->name = 'a';
	(*b)->arr = (int *)malloc(sizeof(int) * (*a)->size);
	(*b)->size = (*a)->size;
	/* last, bottom index */
	(*b)->len = 0;
	(*b)->name = 'b';
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
	init_both(&a, &b, argc, argv);
	/* sort */
	sort_greedy(a, b);
	free_both(a, b);
	return (0);
}
