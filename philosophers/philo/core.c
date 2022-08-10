/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:43 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:44 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "construct.h"
#include "time.h"
#include "shared.h"
#include "routine.h"
#include "monitor.h"
#include "constants.h"
#include "arguments.h"

static void	set_int_elements(int *arr, int count, int val)
{
	int	i;

	i = -1;
	while (++i < count)
		arr[i] = val;
}

static int	set_environments(pthread_t **threads, int **vars)
{
	int	i;
	int	n;
	int	*last_eat;
	int	*n_eat;

	n = access_args(GET).n_philo;
	if (!construct_ints(&last_eat, n) || !construct_ints(&n_eat, n)
		|| !construct_threads(threads, n) || !construct_ints(vars, n))
		return (0);
	i = -1;
	while (++i < n)
		(*vars)[i] = i;
	access_init_time(SET);
	set_int_elements(last_eat, n, get_init_interval() + SYNC_TIME);
	access_last_eat(last_eat, NO_INDEX);
	set_int_elements(n_eat, n, access_args(GET).n_eat);
	access_n_eat(n_eat, NO_INDEX);
	return (1);
}

int	manage_threads(pthread_t **threads)
{
	int	i;
	int	*idx;
	int	n;

	if (!set_environments(threads, &idx))
		return (0);
	i = -1;
	n = access_args(GET).n_philo;
	while (++i < n)
		if (pthread_create(&((*threads)[i]), 0, &routine, &(idx[i])))
			return (0);
	monitor_threads(n, access_args(GET).time_die);
	i = -1;
	while (++i < n)
		pthread_join((*threads)[i], 0);
	free(idx);
	return (1);
}
