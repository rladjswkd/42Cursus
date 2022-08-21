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
#include "naming.h"

static void	unlink_sem_all(void)
{
	int	n;

	sem_unlink(FORK_NAME);
	sem_unlink(RIGHTS_NAME);
	sem_unlink(LAST_EAT_NAME);
	sem_unlink(N_EAT_NAME);
	sem_unlink(DIED_NAME);
	n = access_args(GET).n_philo;
	while (n--)
	{
		sem_unlink(access_flag_names(GET)[n]);
		sem_unlink(access_finish_names(GET)[n]);
	}
}

static int	open_new_sem(sem_t **sem, char *name, int value)
{
	*sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (*sem == SEM_FAILED)
		return (0);
	return (1);
}

static int	init_monitor_sems(char *base, int len, int cond)
{
	sem_t	**sem;
	char	**names;
	int		i;

	sem = (sem_t **)malloc(sizeof(sem_t *) * access_args(GET).n_philo);
	names = (char **)malloc(sizeof(char *) * access_args(GET).n_philo);
	if (!sem || !names)
		return (0);
	i = -1;
	while (++i < access_args(GET).n_philo)
		if (!get_sem_name(i + 1, base, len, &(names[i])))
			return (0);
	while (i--)
		if (!open_new_sem(&(sem[i]), names[i], 1))
			return (0);
	if (cond)
		access_flag_names(names);
	else
		access_finish_names(names);
	if (cond)
		access_flag_sem(sem, NO_INDEX);
	else
		access_finish_sem(sem, NO_INDEX);
	return (1);
}

int	init_sem_all(void)
{
	sem_t	*fork;
	sem_t	*rights;
	sem_t	*last_eat;
	sem_t	*n_eat;
	sem_t	*died;

	if (!open_new_sem(&fork, FORK_NAME, access_args(GET).n_philo)
		|| !open_new_sem(&rights, RIGHTS_NAME, 1)
		|| !open_new_sem(&last_eat, LAST_EAT_NAME, 1)
		|| !open_new_sem(&n_eat, N_EAT_NAME, 1)
		|| !open_new_sem(&died, DIED_NAME, 1))
		return (0);
	access_fork_sem(fork);
	access_rights_sem(rights);
	access_last_eat_sem(last_eat);
	access_n_eat_sem(n_eat);
	access_died_sem(died);
	if (!init_monitor_sems(FLAG_NAME, 5, 1)
		|| !init_monitor_sems(FINISH_NAME, 7, 0))
		return (0);
	unlink_sem_all();
	return (1);
}
