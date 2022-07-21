#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define FORMAT "%dms %d %s\n"
# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define GET	0
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef unsigned long long	t_uint64;
typedef struct	s_args
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	n_eat;
}	t_args;
int	*get_int(char *str, int *val);
#endif
