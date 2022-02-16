/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:21:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 16:16:09 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	if (a)
		free(a->arr);
	free(a);
	if (b)
		free(b->arr);
	free(b);
}

void	exit_on_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_all(a, b);
	exit(EXIT_FAILURE);
}
