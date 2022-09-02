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
#include <stdlib.h>
#include "philo_semaphore.h"
#include "monitor_semaphore.h"
#include "constants.h"
#include "shared.h"

static void	unlink_sem_all(void)
{
	sem_unlink(FORK_NAME);
	sem_unlink(RIGHTS_NAME);
	sem_unlink(LAST_EAT_NAME);
	sem_unlink(N_EAT_NAME);
	sem_unlink(DIED_NAME);
	sem_unlink(FLAG_NAME);
	sem_unlink(FINISH_NAME);
}

static int	open_new_sem(char *name, int value, sem_t *(*fp)(sem_t *))
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (sem == SEM_FAILED)
		return (0);
	(*fp)(sem);
	return (1);
}

int	init_sem_all(void)
{
	int	n;

	n = access_args(GET).n_philo;
	if (!open_new_sem(FORK_NAME, n, access_fork_sem)
		|| !open_new_sem(RIGHTS_NAME, 1, access_rights_sem)
		|| !open_new_sem(LAST_EAT_NAME, 1, access_last_eat_sem)
		|| !open_new_sem(N_EAT_NAME, 1, access_n_eat_sem)
		|| !open_new_sem(FLAG_NAME, n, access_flag_sem)
		|| !open_new_sem(FINISH_NAME, n, access_finish_sem)
		|| !open_new_sem(DIED_NAME, 1, access_died_sem))
		return (0);
	unlink_sem_all();
	return (1);
}
