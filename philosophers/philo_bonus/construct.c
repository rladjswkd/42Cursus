/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:44 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:18:45 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include "philo_semaphore.h"
#include "constants.h"
#include "shared.h"

static int	open_new_sem(sem_t **sem, char *name, int value)
{
	*sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (*sem == SEM_FAILED)
		return (0);
	return (1);
}

int	init_sem_all(void)
{
	sem_t	*fork;
	sem_t	*rights;
	sem_t	*last_eat;
	sem_t	*n_eat;
	sem_t	*flag;

	if (!open_new_sem(&fork, FORK_NAME, access_args(GET).n_philo)
		|| !open_new_sem(&rights, RIGHTS_NAME, 1)
		|| !open_new_sem(&last_eat, LAST_EAT_NAME, 1)
		|| !open_new_sem(&n_eat, N_EAT_NAME, 1)
		|| !open_new_sem(&flag, FLAG_NAME, 1))
		return (0);
	access_fork_sem(fork);
	access_rights_sem(rights);
	access_last_eat_sem(last_eat);
	access_n_eat_sem(n_eat);
	access_flag_sem(flag);
	return (1);
}
