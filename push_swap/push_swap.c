/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 16:16:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init_both(&a, &b, argc, argv);
	if (is_sorted(a))
	{
		free_all(a, b);
		return (0);
	}
	if (a->size > 5)
		sort_greedy(a, b);
	else
		sort_direct(a, b);
	free_all(a, b);
	return (0);
}
