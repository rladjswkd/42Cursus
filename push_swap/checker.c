/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:25:48 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/19 13:02:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	do_rr_rrr(t_stack **a, t_stack **b, int is_forward)
{
	rotate(*a, is_forward);
	rotate(*b, is_forward);
}

static void	do_ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
}

static void	exit_on_error_checker(t_stack *a, t_stack *b, char *op)
{
	free(op);
	exit_on_error(a, b);
}

static void	do_operation(t_stack **a, t_stack **b, char *op)
{
	if (are_same_strings(op, "rrr"))
		do_rr_rrr(a, b, 0);
	else if (are_same_strings(op, "rra"))
		rotate(*a, 0);
	else if (are_same_strings(op, "rrb"))
		rotate(*b, 0);
	else if (are_same_strings(op, "ss"))
		do_ss(a, b);
	else if (are_same_strings(op, "sa"))
		swap(*a);
	else if (are_same_strings(op, "sb"))
		swap(*b);
	else if (are_same_strings(op, "pa"))
		push(*b, *a);
	else if (are_same_strings(op, "pb"))
		push(*a, *b);
	else if (are_same_strings(op, "rr"))
		do_rr_rrr(a, b, 1);
	else if (are_same_strings(op, "ra"))
		rotate(*a, 1);
	else if (are_same_strings(op, "rb"))
		rotate(*b, 1);
	else
		exit_on_error_checker(*a, *b, op);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (argc < 2)
		return (0);
	init_both(&a, &b, argc, argv);
	while (1)
	{
		op = get_next_line();
		if (!op)
			exit_on_error(a, b);
		if (!*op)
			break ;
		do_operation(&a, &b, op);
		free(op);
	}
	if (is_sorted(a) && a->len == a->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(a, b);
	free(op);
	return (0);
}
