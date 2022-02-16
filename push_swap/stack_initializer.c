/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:54:58 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 16:23:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(int *arr, unsigned int s, unsigned int l, char c)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	if (!arr)
	{
		stack->arr = (int *)malloc(sizeof (int) * s);
		if (!(stack->arr))
			return (0);
	}
	else
		stack->arr = arr;
	stack->size = s;
	stack->len = l;
	stack->name = c;
	return (stack);
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
