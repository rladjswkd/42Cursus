#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

sem_t	*access_fork_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_rights_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_last_eat_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_n_eat_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_flag_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}
