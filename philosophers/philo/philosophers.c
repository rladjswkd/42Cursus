#include "philosophers.h"

void	*foo(pthread_mutex_t *mutex)
{

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

int	init_all(pthread_mutex_t *mutexes, pthread_t *threads, int philo_n)
{
	int	i;

	mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_n);
	if (!mutexes)
		return (0);
	i = -1;
	while (++i < philo_n)
		if (pthread_mutex_init(&(mutexes[i]), 0))
			return (destroy_mutexes(mutexes, i));
	threads = (pthread_t *)malloc(sizeof(pthread_t) * philo_n);
	if (!threads)
		return (0);
	i = -1;
	while (++i < philo_n)
		if (pthread_create(&(philo[i]), 0, &foo, mutexes) != 0)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	threads;
	t_philo		philo;

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
	philo.args = args;
	if (!init_all(philo.mutexes, threads, args.philo_n))
		free_all(philo.mutexes, threads, 1);
	/* make threads work repeatedly */
	free_all(mutexes, threads, 0);
	return (0);
}
