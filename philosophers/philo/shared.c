/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:08 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:09 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_args.h"

t_args	access_args(t_args *initializer)
{
	static t_args	args;

	if (initializer)
		args = *initializer;
	return (args);
}

int	*access_last_eat(int *initializer, int index)
{
	static int	*last;

	if (initializer)
		last = initializer;
	return (&(last[index]));
}

int	*access_n_eat(int *initializer, int index)
{
	static int	*count;

	if (initializer)
		count = initializer;
	return (&(count[index]));
}

int	access_flag(int initializer)
{
	static int	flag;

	if (initializer)
		flag = 1;
	return (flag);
}
