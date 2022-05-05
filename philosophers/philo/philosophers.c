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
	lock1 = (thread + args.count - 1) % args.count;
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

int	destroy_mutexes(pthread_mutex_t *mutexes, int error_idx)
{
	int	i;

	i = -1;
	while (++i < error_idx)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

void	free_all(pthread_mutex_t *mutexes, pthread_t *threads, int is_error)
{
	if (mutexes)
		free(mutexes);
	if (threads)
		free(threads);
	if (is_error)
		exit(EXIT_FAILURE);
}

int	init_mutex(pthread_mutex_t *arr)
{
	int		i;
	int		n;

	n = get_args(0).count;
	arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!arr)
		return (0);
	i = -1;
	while (++i < n)
		if (pthread_mutex_init(&(arr[i]), 0))
			return (destroy_mutexes(arr, i));
	get_mutex(arr, 0);
	return (1);
}

int	run_threads(pthread_t *threads)
{
	int	i;
	int	n;
	int	*vars;

	n = get_args(0).count;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if (!threads)
		return (0);
	vars = (int *)malloc(sizeof(int) * n);
	if (!vars)
		return (0);
	i = -1;
	while (++i < n)
	{
		vars[i] = i;
		if (pthread_create(&(threads[i]), 0, &run, &(vars[i])) != 0)
			return (0);
	}
	/* infinite loop and break if one of the philosophers die */
	while (1)
	{}
	free(vars);
	return (1);
}

int	parse_arguments(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (0);
	if (!get_int(argv[1], &(args.count)))
		return (0);
	if (!get_int(argv[2], &(args.die_t)))
		return (0);	
	if (!get_int(argv[3], &(args.eat_t)))
		return (0);
	if (!get_int(argv[4], &(args.sleep_t)))
		return (0);
	if (argc == 6 && !get_int(argv[5], &(args.eat_n)))
		return (0);
	get_args(&args);
	return (1);
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	pthread_mutex_t	*mutexes;

	get_init_time();
	if (!parse_arguments(argc, argv))
		return (0);
	if (!init_mutex(mutexes))
		free_all(mutexes, 0, 1);
	if (!run_threads(threads))
		free_all(mutexes, threads, 1);
	free_all(mutexes, threads, 0);
	return (0);
}
