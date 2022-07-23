#include "philosophers.h"
// todo: init all mutexes rightly and apply pthread_mutex_init
/**************************mutex, critical section****************************/
pthread_mutex_t	*access_fork_mutex(pthread_mutex_t *initializer, int index)
{
	static pthread_mutex_t	*mutex;;

	if (initializer)
		mutex = initializer;
	return (&(mutex[index]));
}

pthread_mutex_t	*access_rights_mutex(pthread_mutex_t *initializer)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (mutex);
}

t_args	access_args(t_args *initializer)
{
	static t_args args;

	if (initializer)
		args = *initializer;
	return (args);
}

pthread_mutex_t	*access_last_eat_mutex(pthread_mutex_t *initializer, int idx)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (&(mutex[idx]));
}

int	*access_last_eat(int *initializer, int index) // need mutex. main thread (monitoring) - philosopher threads
{
	static int	*last;

	if (initializer)
		last = initializer;
	return (&(last[index]));
}

pthread_mutex_t	*access_flag_mutex(pthread_mutex_t *initializer)
{
	static pthread_mutex_t *mutex;

	if (initializer)
		mutex = initializer;
	return (mutex);
}

int	access_flag(int initializer) // need mutex. main thread (monitor) - philosopher threads
{
	static int	flag;

	if (initializer)
		flag = 1;
	return (flag);
}
/*****************************************************************************/
/*************************************time************************************/
struct timeval	access_init_time(int flag)
{
	static struct timeval	init;

	if (flag)
		gettimeofday(&init, (struct timezone *)0);
	return (init);
}

int	convert_to_usec(struct timeval t)
{
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

struct timeval	get_time_now(void)
{
	struct timeval	t;

	gettimeofday(&t, (struct timezone *)0);
	return (t);
}

int	get_interval(struct timeval t1)
{
	return (convert_to_usec(get_time_now()) - convert_to_usec(t1));
}

int	get_usec_now(void)
{
	return (convert_to_usec(get_time_now()));
}
/*****************************************************************************/

void	print_log(int idx, char *state)
{
	
	pthread_mutex_lock(access_rights_mutex(GET));
	printf(FORMAT, get_interval(access_init_time(GET)) - SYNC_TIME
		, idx + 1, state);
	pthread_mutex_unlock(access_rights_mutex(GET));
}

void	swap_forks(int *fork1, int *fork2) // utils
{
	int	temp;

	temp = *fork1;
	*fork1 = *fork2;
	*fork2 = temp;
}

int	is_flag_set(void)
{
	int	res;

	res = 0;
	pthread_mutex_lock(access_flag_mutex(GET));
	if (access_flag(GET))
		res = 1;
	pthread_mutex_unlock(access_flag_mutex(GET));
	return (res);
}

void	usleep_splitted(int time) // utils
{
	int	from;
	int	usec;
	int	current;

	from = get_usec_now();
	usec = time * WEIGHT;
	while (1)
	{
		current = get_usec_now();
		if (current - from >= time)
			return ;
		if (time - (current - from) <= usec)
			usec /= 2;
		usleep(usec);
	}
}

/*************************************step************************************/

int	philo_pickup(int fork, int idx)
{
	if (is_flag_set())
		return (0);
	pthread_mutex_lock(access_fork_mutex(GET, fork));
	print_log(idx, STR_FORK);
	return (1);
}

int	philo_eat_sleep(int idx, int time, int state)
{
	if (is_flag_set())
		return (0);
	if (state == EAT)
	{
		print_log(idx, STR_EAT);
		pthread_mutex_lock(access_last_eat_mutex(GET, idx));
		*access_last_eat(GET, idx) = get_interval(
				access_init_time(GET)) - SYNC_TIME;
		pthread_mutex_unlock(access_last_eat_mutex(GET, idx));
	}
	else
		print_log(idx, STR_SLEEP);
	usleep_splitted(time);
	return (1);
}

int	philo_putdown(int fork)
{
	pthread_mutex_unlock(access_fork_mutex(GET, fork));
	if (is_flag_set())
		return (0);
	return (1);
}

int	philo_think(int idx)
{
	if (is_flag_set())
		return (0);
	print_log(idx, STR_THINK);
	usleep(access_args(GET).time_eat);
	return (1);
}

int	philo_cycle_flag_check(int fork1, int fork2, int idx)
{
	if (!philo_pickup(fork1, idx) || !philo_pickup(fork2, idx)
		|| !philo_eat_sleep(idx, access_args(GET).time_eat, EAT)
		|| !philo_putdown(fork2) || !philo_putdown(fork1)
		|| !philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP)
		|| !philo_think(idx))
		return (0);
       return (1);	
}
/*****************************************************************************/

void	synchronize_start_time(void)
{
	while (get_interval(access_init_time(GET)) < SYNC_TIME)
		usleep(SYNC_USEC);
}

void	*routine(void *param)
{
	int		idx;
	int		fork1;
	int		fork2;

	idx = *((int *)param);
	fork1 = idx;
	fork2 = (idx + 1) % access_args(GET).n_philo;
	if (idx & 1)
		swap_forks(&fork1, &fork2);
	synchronize_start_time();
	while (1)
		if (!philo_cycle_flag_check(fork1, fork2, idx))
			return (0);
	return (0);
}

void	do_monitoring(void)
{
	int	i;
	int	n;
	int	limit;

	n = access_args(GET).n_philo;
	limit = access_args(GET).time_die * 1000;
	while (1)
	{
		i = -1;
		while (++i < n)
		{
			pthread_mutex_lock(access_last_eat_mutex(GET, i));
			if (get_interval(get_time_now()) - *access_last_eat(GET, i) > limit)
			{
				pthread_mutex_lock(access_flag_mutex(GET)); // need to unlock this.
				access_flag(SET);
				pthread_mutex_unlock(access_flag_mutex(GET));
				pthread_mutex_unlock(
						access_last_eat_mutex(GET, i));
				return ;
			}
			pthread_mutex_unlock(access_last_eat_mutex(GET, i));
		}
	}
}

int	destroy_mutex(pthread_mutex_t *mutexes, int error_idx)
{
	int	i;

	i = -1;
	while (++i < error_idx)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

void	destroy_free_mutex(pthread_mutex_t *mutex, int len)
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
	if (access_flag_mutex(GET))
		destroy_free_mutex(access_flag_mutex(GET), 1);
	if (threads)
		free(threads);
	if (is_error)
		exit(EXIT_FAILURE);
}

int	init_mutex(pthread_mutex_t **mutex, int n)
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

	if (!init_mutex(&fork, access_args(GET).n_philo)
		|| !init_mutex(&rights, 1)
		|| !init_mutex(&last_eat, access_args(GET).n_philo)
		|| !init_mutex(&flag, 1))
		return (0);
	access_fork_mutex(fork, NO_INDEX);
	access_rights_mutex(rights);
	access_last_eat_mutex(last_eat, NO_INDEX);
	access_flag_mutex(flag);
	return (1);
}

int	create_threads(pthread_t **threads)
{
	*threads = (pthread_t *)malloc(
			sizeof(pthread_t) * access_args(GET).n_philo);
	if (!(*threads))
		return (0);
	return (1);
}

int	malloc_wrapper_int(int **ptr, int len)
{
	*ptr = (int *)malloc(sizeof(int) * len);
	if (!(*ptr))
		return (0);
	return (1);
}

int	set_environments(pthread_t **threads, int **vars)
{
	int	*last_eat;
	int	init_time;
	int	i;
	int	n;

	if (!create_threads(threads))
		return (0);
	if (!malloc_wrapper_int(vars, access_args(GET).n_philo))
		return (0);
	i = -1;
	n = access_args(GET).n_philo;
	while (++i < n)
		(*vars)[i] = i;
	access_init_time(SET);
	if (!malloc_wrapper_int(&last_eat, n))
		return (0);
	init_time = convert_to_usec(access_init_time(GET));
	i = -1;
	while (++i < n)
		last_eat[i] = init_time;
	access_last_eat(last_eat, NO_INDEX);
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
	do_monitoring();
	i = -1;
	while (++i < n)
		if (pthread_join((*threads)[i], 0))
	free(idx);
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
	if (argc == 6 && !get_int(argv[5], &(args.n_eat)))
		return (0);
	access_args(&args);
	return (1);
}

int	main(int argc, char **argv)
{
	pthread_t		*threads;

	if (!parse_arguments(argc, argv))
		return (0);
	if (!init_mutex_all())
		free_all(0, 1);
	if (!manage_threads(&threads))
		free_all(threads, 1);
	free_all(threads, 0);
	return (0);
}
