#include "philosophers.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

int	is_flag_set(void)
{
	int	res;

	res = 0;
	sem_wait(access_flag_sem(GET));
	if (access_flag(GET))
		res = 1;
	sem_post(access_flag_sem(GET));
	return (res);
}

void	print_log(int idx, char *str)
{
	if (!is_flag_set())
		printf(FORMAT, get_init_interval(), idx + 1, str);
}

void	set_flag(int idx)
{
	sem_wait(access_flag_sem(GET, idx));
	access_flag(SET);
	sem_post(access_flag_sem(GET, idx));
}
/*************************************step************************************/
void	philo_pickup(int idx)
{
	sem_wait(access_fork_sem(GET));
	print_log(idx, STR_FORK);
}

void	philo_eat_sleep(int idx, int time, int state)
{
	if (state == EAT)
	{
		print_log(idx, STR_EAT);
		sem_wait(access_flag_sem(GET);
		*access_last_eat(GET) = get_init_interval();
		(*access_n_eat(GET))--;
		sem_post(access_flag_sem(GET));
	}
	else
		print_log(idx, STR_SLEEP);
	if (!is_flag_set())
		usleep_splitted(time);
}

void	philo_putdown()
{
	sem_post(access_fork_sem(GET));
}

void	philo_think(int idx)
{
	print_log(idx, STR_THINK);
	if (!is_flag_set())
		usleep(access_args(GET).time_eat);
}

int	philo_cycle(int idx)
{
	philo_pickup(idx);
	if (access_args(GET).n_philo == 1)
	{
		sem_post(access_fork_mutex(GET));
		return (0);
	}
	philo_pickup(idx);
	philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
	philo_putdown();
	philo_putdown();
	philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP);
	philo_think(idx);
	return (1);
}
/*****************************************************************************/

void	synchronize_start_time(void)
{
	while (get_init_interval() < 0)
		usleep(SYNC_USEC);
}

void	*routine(void *param)
{
	int		idx;

	synchronize_start_time();
	idx = *((int *)param);
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (!is_flag_set())
		if (!philo_cycle(idx))
			break ;
	return (0);
}

int	get_last_eat(int idx)
{
	int	res;

	sem_wait(access_flag_sem(GET));
	res = *access_last_eat(GET);
	sem_post(access_flag_sem(GET));
	return (res);
}

int	check_if_died(int idx, int limit)
{
	int	now;

	now = get_init_interval();
	if (now - get_last_eat(idx) > limit)
	{
		set_flag();
		printf(FORMAT, now, idx + 1, STR_DIED);
		return (1);
	}
	return (0);
}

int	check_if_done(int idx)
{
	int 	res;

	sem_wait(access_flag_sem(GET));
	res = *access_n_eat(GET);
	sem_post(access_flag_sem(GET));
	return (res < 1);
}

void	monitor_threads(int n, int limit)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < n)
		{
			if (check_if_died(i, limit))
				sem_post(access_program_flag_sem(GET));
			if (check_if_done(i))
				exit(0);
		}
	}
}





int	manage_subprocess(void)
{
	int			i;
	int			n;
	pthread_t	thread;

	// 1. program_flag_sem에 sem_post
	// 2. monitor thread 만들기 routine_monitor. routine_monitor는 progrm_flag_sem에 sem_wait 거는 걸로 시작.
	// 3. n_philo만큼 반복문 돌며 fork
	// 	3.1. pid가 0이면 operate_subprocess 호출
	// 4. i가 n(n_philo)보다 작은 동안 계속 waitpid(-1 ,...) 실행.
	// 5. return (1);
}

void	free_all(int is_error)
{
	sem_close(access_fork_sem(GET));
	sem_close(access_flag_sem(GET));
	sem_close(accses_program_flag_sem(GET));
	sem_unlink(FORK_NAME);
	sem_unlink(FLAG_NAME);
	sem_unlink(PROG_NAME);
	if (access_last_eat(GET)
		free(access_last_eat(GET));
	if (access_n_eat_mutex(GET, 0))
		destroy_free_mutex(access_n_eat_mutex(GET, 0), n);
	if (access_n_eat(GET, 0))
		free(access_n_eat(GET, 0));
	if (is_error)
		exit(EXIT_FAILURE);
}

int	open_new_sem(sem_t **sem, char *name, int value)
{
	*sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (sem == SEM_FAILED)
		return (0);
	return (1);
}

int	init_sem_all(void)
{
	sem_t	*fork;
	sem_t	*flag;
	sem_t	*program_flag;

	if (!open_new_sem(&fork, FORK_NAME, access_args(GET).n_philo))
		return (0);
	if (!open_new_sem(&flag, FLAG_NAME, 1))
		return (0);
	if (!open_new_sem(&program_flag, PROG_NAME, 1))
		return (0);
	access_fork_sem(fork);
	access_flag_sem(flag);
	access_program_flag_sem(program_flag);
	return (1);
}

int	parse_arguments(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (0);
	if (!get_int(argv[1], &(args.n_philo)))
		return (0);
	if (!get_int(argv[2], &(args.time_die)))
		return (0);	
	if (!get_int(argv[3], &(args.time_eat)))
		return (0);
	if (!get_int(argv[4], &(args.time_sleep)))
		return (0);
	if (argc == 5)
		args.n_eat = MAX_INT;
	else if (argc == 6 && !get_int(argv[5], &(args.n_eat)))
		return (0);
	access_args(&args);
	return (1);
}

int	main(int argc, char **argv)
{
	// access_program_flag_sem에 대해 sem_wait을 main process의 monitor를 생성하기 전에 수행해야 한다.
	if (!parse_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_sem_all())
		free_all(1);
	if (!manage_subprocess())
		free_all(1);
	free_all(0);
	return (0);
}
