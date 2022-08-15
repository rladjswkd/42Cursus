/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:15 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:17 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "struct_args.h"

t_args	access_args(t_args *initializer)
{
	static t_args args;

	if (initializer)
		args = *initializer;
	return (args);
}

pthread_t	access_monitor_thread(pthread_t initializer)
{
	static	pthread_t	tid;

	if (initializer)
		tid = initializer;
	return (tid);
}

int	*access_last_eat(int initializer)
{
	static int	last;

	if (initializer)
		last = initializer;
	return (&last);
}

int	*access_n_eat(int initializer)
{
	static int	count;

	if (initializer)
		count = initializer;
	return (&count);
}
