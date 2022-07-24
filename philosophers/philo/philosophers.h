#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define FORMAT 	"%dms %d %s\n"
# define STR_FORK	"has taken a fork"
# define STR_EAT	"is eating"
# define STR_SLEEP	"is sleeping"
# define STR_THINK	"is thinking"
# define STR_DIED	"is died"
# define GET		0
# define SET		1
# define NO_INDEX	0
# define SYNC_TIME	5
# define SYNC_USEC	100
# define WEIGHT		333
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef enum	e_state
{
	EAT,
	SLEEP
}	t_state;
typedef struct	s_args
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	n_eat;
}	t_args;
int	get_int(char *str, int *val);
#endif
