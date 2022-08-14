/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shared.h"
#include "constants.h"
#include "mutexes.h"

int	destroy_mutex(pthread_mutex_t *mutexes, int error_idx)
{
	int	i;

	i = -1;
	while (++i < error_idx)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

static void	destroy_free_mutex(pthread_mutex_t *mutex, int len)
{
	destroy_mutex(mutex, len);
	free(mutex);
}

void	free_all(pthread_t *threads, int is_error)
{
	int	n;

	n = access_args(GET).n_philo;
	if (access_fork_mutex(GET, 0))
		destroy_free_mutex(access_fork_mutex(GET, 0), n);
	if (access_rights_mutex(GET))
		destroy_free_mutex(access_rights_mutex(GET), 1);
	if (access_last_eat_mutex(GET, 0))
		destroy_free_mutex(access_last_eat_mutex(GET, 0), n);
	if (access_last_eat(GET, 0))
		free(access_last_eat(GET, 0));
	if (access_n_eat_mutex(GET, 0))
		destroy_free_mutex(access_n_eat_mutex(GET, 0), n);
	if (access_n_eat(GET, 0))
		free(access_n_eat(GET, 0));
	if (access_flag_mutex(GET))
		destroy_free_mutex(access_flag_mutex(GET), 1);
	if (threads)
		free(threads);
	if (is_error)
		exit(EXIT_FAILURE);
}
