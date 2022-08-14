#ifndef SEMAPHORE_H
# define SEMAPOHRE_H
# include <semaphore.h>

sem_t	*access_fork_sem(sem_t *initializer);
sem_t	*access_rights_sem(sem_t *initializer);
sem_t	*access_last_eat_sem(sem_t *initializer);
sem_t	*access_n_eat_sem(sem_t *initializer);
sem_t	*access_flag_sem(sem_t *initializer);
#endif
