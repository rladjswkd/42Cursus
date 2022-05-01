#include "philosophers.h"
#include <stdio.h>

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

void	*run_philo(void *mutex_idx)
{
	int	index;

	index = *((int *)mutex_idx);
	printf("%d is locked\n", index);
	pthread_mutex_lock(get_mutex(0, index));
	pthread_mutex_unlock(get_mutex(0, index));
	printf("%d is unlocked\n", index);
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
	i = -1;
	while (++i < philo_n)
		if (pthread_create(&((*threads)[i]), 0, &run_philo, &i) != 0)
			return (0);
	pthread_join((*threads)[0], (void **)0);
	pthread_join((*threads)[1], (void **)0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	*threads;
	pthread_mutex_t	*mutexes;

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
