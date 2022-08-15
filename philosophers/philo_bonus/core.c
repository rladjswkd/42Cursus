/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:18:51 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo_semaphore.h"
#include "constants.h"
#include "shared.h"
#include "subprocess.h"
#include "time.h"

static void	close_sem_all(void)
{
	sem_close(access_fork_sem(GET));
	sem_close(access_rights_sem(GET));
	sem_close(access_last_eat_sem(GET));
	sem_close(access_n_eat_sem(GET));
	sem_close(access_flag_sem(GET));
}

static void	monitor_main(pid_t *pid_list)
{
	int		i;
	int		n;

	i = -1;
	n = access_args(GET).n_philo;
	sem_wait(access_flag_sem(GET));
	while (++i < n)
		kill(pid_list[i], SIGTERM);
}

static void	set_environments(void)
{
	access_init_time(SET);
	access_last_eat(get_init_interval() + SYNC_TIME);
	access_n_eat(access_args(GET).n_eat);
}

int	manage_subprocess(void)
{
	int			i;
	int			n;
	pid_t		*pid_list;
	pthread_t	main_monitor;

	// 1. flag_sem에 sem_wait
	sem_wait(access_flag_sem(GET));
	// 2. n_philo만큼 반복문 돌며 fork
	// 2.1. pid가 0이면 operate_subprocess 호출
	set_environments();
	n = access_args(GET).n_philo;
	pid_list = (pid_t *)malloc(sizeof(pid_t) * n);
	if (!pid_list)
		return (0);
	i = -1;
	while (++i < n)
	{
		pid_list[i] = fork();
		if (pid_list[i] == 0)
			func_philo(i);
	}
	// 3. monitor thread 만들기 monitor_main. flag_sem에 sem_wait 거는 걸로 시작. monitor thread 만들 필요 없네! monitor 함수 실행
	monitor_main(pid_list);
	// 4. i가 n(n_philo)보다 작은 동안 계속 waitpid(-1 ,...) 실행.
	i = -1;
	while (++i < n)
		waitpid(-1, 0, 0);
	free(pid_list);
	close_sem_all();
	// 5. return (1);
	return (1);
}
