/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:23:46 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:23:54 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "constants.h"
#include "shared.h"
#include "mutexes.h"
#include "destruct.h"

static int	init_mutex(pthread_mutex_t **mutex, int n)
{
	int	i;

	*mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!(*mutex))
		return (0);
	i = -1;
	while (++i < n)
		if (pthread_mutex_init(&((*mutex)[i]), 0))
			return (destroy_mutex((*mutex), i));
	return (1);
}

int	init_mutex_all(void)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*rights;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*flag;
	pthread_mutex_t	*n_eat;

	if (!init_mutex(&fork, access_args(GET).n_philo)
		|| !init_mutex(&rights, 1)
		|| !init_mutex(&last_eat, access_args(GET).n_philo)
		|| !init_mutex(&flag, 1)
		|| !init_mutex(&n_eat, access_args(GET).n_philo))
		return (0);
	access_fork_mutex(fork, NO_INDEX);
	access_rights_mutex(rights);
	access_last_eat_mutex(last_eat, NO_INDEX);
	access_flag_mutex(flag);
	access_n_eat_mutex(n_eat, NO_INDEX);
	return (1);
}

int	construct_threads(pthread_t **thread_p, int len)
{
	*thread_p = (pthread_t *)malloc(sizeof(pthread_t) * len);
	if (!(*thread_p))
		return (0);
	return (1);
}

int	construct_ints(int **int_p, int len)
{
	*int_p = (int *)malloc(sizeof(int) * len);
	if (!(*int_p))
		return (0);
	return (1);
}
