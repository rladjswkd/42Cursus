#include "philosophers.h"

pthread_mutex_t	*access_mutex(pthread_mutex_t *initializer, int index)
{
	static pthread_mutex_t	*mutexes;

	if (initializer)
		mutexes = initializer;
	return (&(mutexes[index]));
}

pthread_mutex_t	*access_rights(pthread_mutex_t *initializer)
{
	static pthread_mutex_t	*rights;

	if (initializer)
		rights = initializer;
	return (rights);
}

t_args	access_args(t_args *initializer)
{
	static t_args args;

	if (initializer)
		args = *initializer;
	return (args);
}

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

int	get_interval(struct timeval t1)
{
	struct timeval	t2;

	gettimeofday(&t2, (struct timezone *)0);
	return (convert_to_usec(t2) - convert_to_usec(t1));
}

void	print_log(int idx, char *state)
{
	pthread_mutex_lock(access_rights(GET));
	printf(FORMAT, get_interval(access_init_time(GET)) - START
		, idx + 1, state);
	pthread_mutex_unlock(access_rights(GET));
}

void	swap_forks(int *fork1, int *fork2)
{
	int	temp;

	temp = *fork1;
	*fork1 = *fork2;
	*fork2 = temp;
}

void	philo_pickup(int fork, int idx)
{
	pthread_mutex_lock(access_mutex(GET, fork));
	print_log(idx, FORK);
}

int	get_current_usec(void)
{
	struct	timeval	t;

	gettimeofday(&t, (struct timeval *)0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	usleep_iterative(int time)
{
	int	from;
	int	usec;
	int	current;

	from = get_current_usec();
	usec = time * 333;
	while (1)
	{
		current = get_current_usec();
		if (current - from >= time)
			return ;
		if (time - (current - from) <= usec)
			usec /= 2;
		usleep(usec);
	}
}

void	philo_eat_sleep(int idx, int time, char *state)
{
	print_log(idx, state);
	usleep_iterative(time);
}

void	philo_putdown(int fork)
{
	pthread_mutex_unlock(access_mutex(GET, fork));
}

void	philo_think(int idx, char *state)
{
	print_log(idx, THINK);
	usleep(access_args(GET).time_eat);
}

void	synchronize_start_time(void)
{
	while (get_interval(access_init_time(0)) < START)
		usleep(100);
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
	{
		philo_pickup(fork1, idx);
		philo_pickup(fork2, idx);
		philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
		philo_putdown(fork2);
		philo_putdown(fork1);
		philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP);
		print_log(idx, THINK);
	}
	return (0);
}

int	destroy_mutexes(pthread_mutex_t *mutexes, int error_idx)
{
	int	i;

	i = -1;
	while (++i < error_idx)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

void	free_all(pthread_t *threads, int is_error)
{
	if (access_mutex(GET, 0))
		free(access_mutex(GET, 0));
	if (access_rights(GET))
		free(access_rights(GET));
	if (threads)
		free(threads);
	if (is_error)
		exit(EXIT_FAILURE);
}

int	init_mutex(void)
{
	int			i;
	int			n;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*rights;

	n = access_args(0).n_philo;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!mutex)
		return (0);
	i = -1;
	while (++i < n)
		if (pthread_mutex_init(&(mutex[i]), 0))
			return (destroy_mutexes(mutex, i));
	access_mutex(mutex, 0);
	rights = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!rights)
		return (0);
	pthread_mutex_init(rights, 0);
	access_rights(rights);
	return (1);
}

int	run_threads(pthread_t *threads)
{
	int	i;
	int	n;
	int	*idx;

	n = access_args(0).n_philo;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if (!threads)
		return (0);
	idx = (int *)malloc(sizeof(int) * n);
	if (!idx)
		return (0);
	i = -1;
	access_init_time(1);
	while (++i < n)
	{
		idx[i] = i;
		if (pthread_create(&(threads[i]), 0, &routine, &(idx[i])) != 0)
			return (0);
	}
	/* infinite loop. break ; if one of the philosophers die */
	while (1)
	{}
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
	if (!init_mutex())
		free_all(0, 1);
	if (!run_threads(threads))
		free_all(threads, 1);
	free_all(threads, 0);
	return (0);
}
