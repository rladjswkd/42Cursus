#include "philosophers.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
// todo: init all mutexes rightly and apply pthread_mutex_init
/**************************mutex, critical section****************************/
pthread_mutex_t	*access_fork_mutex(pthread_mutex_t *initializer, int index)
{
	static pthread_mutex_t	*mutex;;

	if (initializer)
		mutex = initializer;
	return (&(mutex[index]));
}

/*
pthread_mutex_t	*access_rights_mutex(pthread_mutex_t *initializer)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (mutex);
}
*/

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

pthread_mutex_t	*access_n_eat_mutex(pthread_mutex_t *initializer, int idx)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (&(mutex[idx]));
}

int	*access_n_eat(int *initializer, int index) // need mutex. main thread (monitoring) - philosopher threads
{
	static int	*count;

	if (initializer)
		count = initializer;
	return (&(count[index]));
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

int	get_init_interval()
{
	return (convert_to_usec(get_time_now()) - SYNC_TIME
			- convert_to_usec(access_init_time(GET)));
}

/*****************************************************************************/

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

void	print_log(int idx, char *str)
{
//	pthread_mutex_lock(access_rights_mutex(GET));
	if (!is_flag_set())
		printf(FORMAT, get_init_interval(), idx + 1, str);
//	pthread_mutex_unlock(access_rights_mutex(GET));
}

void	swap_forks(int *fork1, int *fork2) // utils
{
	int	temp;

	temp = *fork1;
	*fork1 = *fork2;
	*fork2 = temp;
}

void	usleep_splitted(int time) // utils
{
	int	from;
	int	usec;
	int	current;

	from = convert_to_usec(get_time_now());
	usec = time * WEIGHT;
	while (1)
	{
		current = convert_to_usec(get_time_now());
		if (current - from >= time)
			return ;
		if (time - (current - from) <= usec)
			usec /= 2;
		usleep(usec);
	}
}

void	set_flag(void)
{
	pthread_mutex_lock(access_flag_mutex(GET));
	access_flag(SET);
	pthread_mutex_unlock(access_flag_mutex(GET));
}

/*************************************step************************************/
void	philo_pickup(int fork, int idx)
{
	pthread_mutex_lock(access_fork_mutex(GET, fork));
	print_log(idx, STR_FORK);
}

void	philo_eat_sleep(int idx, int time, int state)
{
	if (state == EAT)
	{
		print_log(idx, STR_EAT);
		pthread_mutex_lock(access_last_eat_mutex(GET, idx));
		*access_last_eat(GET, idx) = get_init_interval();
		pthread_mutex_unlock(access_last_eat_mutex(GET, idx));
		pthread_mutex_lock(access_n_eat_mutex(GET, idx));
		(*access_n_eat(GET, idx))--;
		pthread_mutex_unlock(access_n_eat_mutex(GET, idx));
	}
	else
		print_log(idx, STR_SLEEP);
	if (!is_flag_set())
		usleep_splitted(time);
}

void	philo_putdown(int fork)
{
	pthread_mutex_unlock(access_fork_mutex(GET, fork));
}

void	philo_think(int idx)
{
	print_log(idx, STR_THINK);
	if (!is_flag_set())
		usleep(access_args(GET).time_eat);
}

int	philo_cycle(int fork1, int fork2, int idx)
{
	philo_pickup(fork1, idx);
	if (fork1 == fork2)
	{
		pthread_mutex_unlock(access_fork_mutex(GET, fork1));
		return (0);
	}
	philo_pickup(fork2, idx);
	philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
	philo_putdown(fork2);
	philo_putdown(fork1);
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
	int		fork1;
	int		fork2;

	synchronize_start_time();
	idx = *((int *)param);
	fork1 = idx;
	fork2 = (idx + 1) % access_args(GET).n_philo;
//	if (idx & 1)
//		swap_forks(&fork1, &fork2);
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (!is_flag_set())
		if (!philo_cycle(fork1, fork2, idx))
			break ;
	return (0);
}

int	get_last_eat(int idx)
{
	int	res;

	pthread_mutex_lock(access_last_eat_mutex(GET, idx));
	res = *access_last_eat(GET, idx);
	pthread_mutex_unlock(access_last_eat_mutex(GET, idx));
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

	pthread_mutex_lock(access_n_eat_mutex(GET, idx));
	res = *access_n_eat(GET, idx);
	pthread_mutex_unlock(access_n_eat_mutex(GET, idx));
	return (res < 1);
}

void	monitor_threads(int n, int limit)
{
	int	i;
	int	done_cnt;

	while (1)
	{
		done_cnt = 0;
		i = -1;
		while (++i < n)
		{
			if (check_if_died(i, limit))
				return ;
			if (check_if_done(i))
				done_cnt++;
		}
		if (done_cnt == access_args(GET).n_philo)
		{
			set_flag();
			return ;
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
//	if (access_rights_mutex(GET))
//		destroy_free_mutex(access_rights_mutex(GET), 1);
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
//	pthread_mutex_t	*rights;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*flag;
	pthread_mutex_t	*n_eat;

	if (!init_mutex(&fork, access_args(GET).n_philo)
//		|| !init_mutex(&rights, 1)
		|| !init_mutex(&last_eat, access_args(GET).n_philo)
		|| !init_mutex(&flag, 1)
		|| !init_mutex(&n_eat, access_args(GET).n_philo))
		return (0);
	access_fork_mutex(fork, NO_INDEX);
//	access_rights_mutex(rights);
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

void	set_int_elements(int *arr, int count, int val)
{
	int	i;

	i = -1;
	while (++i < count)
		arr[i] = val;
}

int	set_environments(pthread_t **threads, int **vars)
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
		args.n_eat = 2147483647;
	else if (argc == 6 && !get_int(argv[5], &(args.n_eat)))
		return (0);
	access_args(&args);
	return (1);
}

int	main(int argc, char **argv)
{
	pthread_t		*threads;

	if (!parse_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_mutex_all())
		free_all(0, 1);
	if (!manage_threads(&threads))
		free_all(threads, 1);
	free_all(threads, 0);
	return (0);
}
