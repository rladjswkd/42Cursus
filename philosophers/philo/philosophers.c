#include "philosophers.h"

pthread_mutex_t	*get_mutex(pthread_mutex_t *initializer, int index)
{
	static pthread_mutex_t	*mutexes = (pthread_mutex_t *)0;

	if (!mutexes)
		mutexes = initializer;
	return (&(mutexes[index]));
}

t_args	get_args(t_args *initializer)
{
	static t_args *args = (t_args *)0;

	if (!args)
		args = initializer;
	return (*args);
}

struct timeval	get_init_time(void)
{
	static struct timeval	init = (struct timeval){0, 0};

	if (!(init.tv_sec))
		gettimeofday(&init, 0);
	return (init);
}

int	get_timestamp(struct timeval from)
{
	struct timeval	to;

	gettimeofday(&to, 0);
	return ((to.tv_sec - from.tv_sec) * 1000
			+ (to.tv_usec - from.tv_usec) / 1000);
}

void	*run(void *index)
{
	struct timeval	init;
	int		thread;
	int		lock1;
	int		lock2;
	t_args		args;

	init = get_init_time();
	thread = *((int *)index);
	args = get_args(0);
	lock1 = (thread + args.philo_n - 1) % args.philo_n;
	lock2 = thread;
	if (thread & 1)
	{
		lock2 = lock1;
		lock1 = thread;
	}
	while (1)
	{
		pthread_mutex_lock(get_mutex(0, lock1));
		printf("%d %d %s\n", get_timestamp(init), thread + 1, "has taken a fork");
		pthread_mutex_lock(get_mutex(0, lock2));
		printf("%d %d %s\n", get_timestamp(init), thread + 1, "has taken a fork");
		printf("%d %d %s\n", get_timestamp(init), thread + 1, "is eating");
		usleep(args.eat_t * 1000);
		pthread_mutex_unlock(get_mutex(0, lock2));
		pthread_mutex_unlock(get_mutex(0, lock1));
		printf("%d %d %s\n", get_timestamp(init), thread + 1, "is sleeping");
		usleep(args.sleep_t * 1000);
		printf("%d %d %s\n", get_timestamp(init), thread + 1, "is thinking");
	}
	return (0);
}

int	destroy_mutexes(pthread_mutex_t *mutexes, int error)
{
	int	i;

	i = -1;
	while (++i < error)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

void	free_all(pthread_mutex_t *mutexes, pthread_t *threads, int error)
{
	if (mutexes)
		free(mutexes);
	if (threads)
		free(threads);
	if (error)
		exit(EXIT_FAILURE);
}

int	init_all(pthread_mutex_t **mutexes, pthread_t **threads, int philo_n)
{
	int	i;
	int	*index;

	*mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_n);
	if (!(*mutexes))
		return (0);
	i = -1;
	while (++i < philo_n)
		if (pthread_mutex_init(&((*mutexes)[i]), 0))
			return (destroy_mutexes(*mutexes, i));
	/* using singleton, make getter of mutexes */
	get_mutex(*mutexes, 0);
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * philo_n);
	if (!(*threads))
		return (0);
	index = (int *)malloc(sizeof(int) * philo_n);
	if (!index)
		return (0);
	i = -1;
	while (++i < philo_n)
	{
		index[i] = i;
		if (pthread_create(&((*threads)[i]), 0, &run, &(index[i])) != 0)
			return (0);
	}
	pthread_join((*threads)[0], 0);
	pthread_join((*threads)[1], 0);
	pthread_join((*threads)[2], 0);
	pthread_join((*threads)[3], 0);
	pthread_join((*threads)[4], 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	*threads;
	pthread_mutex_t	*mutexes;
	
	get_init_time();
	if (argc != 5 && argc != 6)
		return (0);
	if (!get_int(argv[1], &(args.philo_n)))
		return (0);
	if (!get_int(argv[2], &(args.die_t)))
		return (0);	
	if (!get_int(argv[3], &(args.eat_t)))
		return (0);
	if (!get_int(argv[4], &(args.sleep_t)))
		return (0);
	if (argc == 6 && !get_int(argv[5], &(args.eat_n)))
		return (0);
	/* using singleton, make getter of args */
	get_args(&args);
	if (!init_all(&mutexes, &threads, args.philo_n))
		free_all(mutexes, threads, 1);
	/* make threads work repeatedly */
	/**/
	free_all(mutexes, threads, 0);
	return (0);
}
