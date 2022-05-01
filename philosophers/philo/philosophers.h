#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct	s_args
{
	int	philo_n;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_n;
}	t_args;
typedef struct	s_philo
{
	pthread_mutex_t	*mutexes;
	t_args		args;

}
int	*get_int(char *str, int *val);

#endif
