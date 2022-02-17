/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:25:48 by gyepark           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/17 19:47:37 by gyepark          ###   ########.fr       */
=======
/*   Updated: 2022/02/17 12:53:56 by gyepark          ###   ########.fr       */
>>>>>>> da1fee4f327065c0a9b742ecaf0b5fb6e8848234
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
		exit_on_error(*a, *b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (!(argc > 1 && init_both(&a, &b, argc, argv)))
		return (0);
	op = get_next_line();
	while (op)
	{
		do_operation(&a, &b, op);
		free(op);
		op = get_next_line();
	}
	if (is_sorted(a) && a->len == a->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(a, b);
	return (0);
}
