#include "philosophers.h"

static int	create_philosophers(pthread_t *philos, int philo_n)
{
	int	i;

	philo = (pthread_t *)malloc(sizeof(pthread_t) * philo_n);
	if (!philo)
		return (0);
	i = -1;
	while (++i < philo_n)
		if (pthread_create() != 0)
		       break ;
	// exit after free philo
}

int	main(int argc, char **argv)
{
	t_args	args;
	pthread_t	*philos;

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
	
	return (0);
}
