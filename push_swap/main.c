/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/01/29 14:58:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* todo */
/* 1. change the code to accept command line arguments like "1 2 3" 4 5 */

#include "push_swap.h"

static void	init_a(t_stack *a, int argc, char **argv)
{
	a->arr = get_ints(argc, argv);
	a->size = argc - 1;
	a->len = a->size;
}

static void	init_b(t_stack *b, t_stack *a)
{
	b->arr = (int *)malloc(sizeof(int) * a->size);
	b->size = a->size;
	/* last, bottom index */
	b->len = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;
	/* do todo 1. here and update argc, argv to represent newly created int list */
	init_a(&a, argc, argv);
	init_b(&b, &a);
	/* sort */
	free(a.arr);
	free(b.arr);
	return (0);
}
