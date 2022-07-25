#include "philosophers.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
// todo: init all mutexes rightly and apply pthread_mutex_init
/**************************mutex, critical section****************************/
sem_t	*access_fork_sem(sem_t *initializer) // count : n_philo
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

t_args	access_args(t_args *initializer)
{
	static t_args args;

	if (initializer)
		args = *initializer;
	return (args);
}

sem_t	*access_last_eat_sem(sem_t *initializer, int index) // semaphore value : 1 (main thread - monitor thread)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (&(sem[index]));
}

int	*access_last_eat(int *initializer) // 하나만 생성해도 자식 프로세스의 가상 메모리 공간은 다르다.
{
	static int	*last;

	if (initializer)
		last = initializer;
	return (last);
}

sem_t	*access_n_eat_sem(sem_t *initializer, int index) // semaphore value : 1 (main thread - monitor thread)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (&(sem[index]));
}

int	*access_n_eat(int *initializer) // 하나만 생성해도 자식 프로세스의 가상 메모리 공간은 다르기 때문에 다른 공간이게 된다.
{
	static int	*count;

	if (initializer)
		count = initializer;
	return (&(count[index]));
}

sem_t	*access_thread_flag_sem(sem_t *initalizer, int index)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (&(sem[index]));
}

int	access_thread_flag(int initializer)
{
	static int	flag;

	if (initializer)
		flag = 1;
	return (flag);
}
// 한 자식 프로세스가 종료 조건을 만족하면, 이 semaphore를 잠그고 exit한다.
// 이후에 이 semaphore에 대해 sem_post연산을 메인에서 수행해준 후 종료한다.
sem_t	*access_program_flag_sem(sem_t *initializer) // semaphore value : 1 (main thread - monitor thread)
{
	static sem_t *sem;

	if (initializer)
		sem = initializer;
	return (sem);
}
/*****************************************************************************/
/*************************************time************************************/
struct timeval	access_init_time(int flag)
{
	static struct timeval	init;

	if (flag)
		gettimeofday(&init, (struct timezone *)0);
	return (init);
}

int	convert_to_usec(struct timeval t)
{
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

struct timeval	get_time_now(void)
{
	struct timeval	t;

	gettimeofday(&t, (struct timezone *)0);
	return (t);
}

int	get_init_interval()
{
	return (convert_to_usec(get_time_now()) - SYNC_TIME
			- convert_to_usec(access_init_time(GET)));
}

/*****************************************************************************/
int	is_flag_set(void)
{
	int	res;

	res = 0;
	pthread_mutex_lock(access_flag_mutex(GET));
	if (access_flag(GET))
		res = 1;
	pthread_mutex_unlock(access_flag_mutex(GET));
	return (res);
}

void	print_log(int idx, char *str)
{
	if (!is_flag_set())
		printf(FORMAT, get_init_interval(), idx + 1, str);
}

void	usleep_splitted(int time) // utils
{
	int	from;
	int	usec;
	int	current;

	from = convert_to_usec(get_time_now());
	usec = time * WEIGHT;
	while (1)
	{
		current = convert_to_usec(get_time_now());
		if (current - from >= time)
			return ;
		if (time - (current - from) <= usec)
			usec /= 2;
		usleep(usec);
	}
}

void	set_flag(int idx)
{
	sem_wait(access_thread_flag_sem(GET, idx));
	access_flag(SET);
	sem_post(access_thread_flag_sem(GET, idx));
}
/*************************************step************************************/
void	philo_pickup(int idx)
{
	sem_wait(access_fork_sem(GET));
	print_log(idx, STR_FORK);
}

void	philo_eat_sleep(int idx, int time, int state)
{
	if (state == EAT)
	{
		print_log(idx, STR_EAT);
		sem_wait(access_last_eat_sem(GET, idx));
		*access_last_eat(GET) = get_init_interval();
		sem_post(access_last_eat_sem(GET, idx));
		sem_wait(access_n_eat_sem(GET, idx));
		(*access_n_eat(GET))--;
		sem_post(access_n_eat_sem(GET, idx));
	}
	else
		print_log(idx, STR_SLEEP);
	if (!is_flag_set())
		usleep_splitted(time);
}

void	philo_putdown()
{
	sem_post(access_fork_sem(GET));
}

void	philo_think(int idx)
{
	print_log(idx, STR_THINK);
	if (!is_flag_set())
		usleep(access_args(GET).time_eat);
}

int	philo_cycle(int idx)
{
	philo_pickup(idx);
	if (access_args(GET).n_philo == 1)
	{
		sem_post(access_fork_mutex(GET));
		return (0);
	}
	philo_pickup(idx);
	philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
	philo_putdown();
	philo_putdown();
	philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP);
	philo_think(idx);
	return (1);
}
/*****************************************************************************/

void	synchronize_start_time(void)
{
	while (get_init_interval() < 0)
		usleep(SYNC_USEC);
}

void	*routine(void *param)
{
	int		idx;

	synchronize_start_time();
	idx = *((int *)param);
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (!is_flag_set())
		if (!philo_cycle(idx))
			break ;
	return (0);
}

int	get_last_eat(int idx)
{
	int	res;

	sem_wait(access_last_eat_sem(GET, idx));
	res = *access_last_eat(GET);
	sem_post(access_last_eat_sem(GET, idx));
	return (res);
}

int	check_if_died(int idx, int limit)
{
	int	now;

	now = get_init_interval();
	if (now - get_last_eat(idx) > limit)
	{
		set_flag();
		printf(FORMAT, now, idx + 1, STR_DIED);
		return (1);
	}
	return (0);
}

int	check_if_done(int idx)
{
	int 	res;

	sem_wait(access_n_eat_sem(GET, idx));
	res = *access_n_eat(GET);
	sem_post(access_n_eat_sem(GET, idx));
	return (res < 1);
}

void	monitor_threads(int n, int limit)
{
	int	i;

	while (1)
	{
		done_cnt = 0;
		i = -1;
		while (++i < n)
		{
			if (check_if_died(i, limit))
				sem_post(access_program_flag_sem(GET)); // 이 부분 하던 중.
			if (check_if_done(i))
				done_cnt++;
		}
	}
}

int	destroy_mutex(pthread_mutex_t *mutexes, int error_idx)
{
	int	i;

	i = -1;
	while (++i < error_idx)
		pthread_mutex_destroy(&(mutexes[i]));
	return (0);
}

void	destroy_free_mutex(pthread_mutex_t *mutex, int len)
{
	destroy_mutex(mutex, len);
	free(mutex);
}

void	free_all(pthread_t *threads, int is_error)
{
	int	n;

	n = access_args(GET).n_philo;
	if (access_fork_mutex(GET, 0))
		destroy_free_mutex(access_fork_mutex(GET, 0), n);
//	if (access_rights_mutex(GET))
//		destroy_free_mutex(access_rights_mutex(GET), 1);
	if (access_last_eat_mutex(GET, 0))
		destroy_free_mutex(access_last_eat_mutex(GET, 0), n);
	if (access_last_eat(GET, 0))
		free(access_last_eat(GET, 0));
	if (access_n_eat_mutex(GET, 0))
		destroy_free_mutex(access_n_eat_mutex(GET, 0), n);
	if (access_n_eat(GET, 0))
		free(access_n_eat(GET, 0));
	if (access_flag_mutex(GET))
		destroy_free_mutex(access_flag_mutex(GET), 1);
	if (threads)
		free(threads);
	if (is_error)
		exit(EXIT_FAILURE);
}

int	init_mutex(pthread_mutex_t **mutex, int n)
{
	int	i;

	*mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!(*mutex))
		return (0);
	i = -1;
	while (++i < n)
		if (pthread_mutex_init(&((*mutex)[i]), 0))
			return (destroy_mutex((*mutex), i));
	return (1);
}

int	init_mutex_all(void)
{
	pthread_mutex_t	*fork;
//	pthread_mutex_t	*rights;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*flag;
	pthread_mutex_t	*n_eat;

	if (!init_mutex(&fork, access_args(GET).n_philo)
//		|| !init_mutex(&rights, 1)
		|| !init_mutex(&last_eat, access_args(GET).n_philo)
		|| !init_mutex(&flag, 1)
		|| !init_mutex(&n_eat, access_args(GET).n_philo))
		return (0);
	access_fork_mutex(fork, NO_INDEX);
//	access_rights_mutex(rights);
	access_last_eat_mutex(last_eat, NO_INDEX);
	access_flag_mutex(flag);
	access_n_eat_mutex(n_eat, NO_INDEX);
	return (1);
}

int	construct_threads(pthread_t **thread_p, int len)
{
	*thread_p = (pthread_t *)malloc(sizeof(pthread_t) * len);
	if (!(*thread_p))
		return (0);
	return (1);
}

int	construct_ints(int **int_p, int len)
{
	*int_p = (int *)malloc(sizeof(int) * len);
	if (!(*int_p))
		return (0);
	return (1);
}

void	set_int_elements(int *arr, int count, int val)
{
	int	i;

	i = -1;
	while (++i < count)
		arr[i] = val;
}

int	set_environments(pthread_t **threads, int **vars)
{
	int	i;
	int	n;
	int	*last_eat;
	int	*n_eat;

	n = access_args(GET).n_philo;
	if (!construct_ints(&last_eat, n) || !construct_ints(&n_eat, n)
		|| !construct_threads(threads, n) || !construct_ints(vars, n))
		return (0);
	i = -1;
	while (++i < n)
		(*vars)[i] = i;
	access_init_time(SET);
	set_int_elements(last_eat, n, get_init_interval() + SYNC_TIME);
	access_last_eat(last_eat, NO_INDEX);
	set_int_elements(n_eat, n, access_args(GET).n_eat);
	access_n_eat(n_eat, NO_INDEX);
	return (1);
}

int	manage_threads(pthread_t **threads)
{
	int	i;
	int	*idx;
	int	n;

	if (!set_environments(threads, &idx))
		return (0);
	i = -1;
	n = access_args(GET).n_philo;
	while (++i < n)
		if (pthread_create(&((*threads)[i]), 0, &routine, &(idx[i])))
			return (0);
	monitor_threads(n, access_args(GET).time_die);
	i = -1;
	while (++i < n)
		pthread_join((*threads)[i], 0);
	free(idx);
	return (1);
}

int	parse_arguments(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (0);
	if (!get_int(argv[1], &(args.n_philo)))
		return (0);
	if (!get_int(argv[2], &(args.time_die)))
		return (0);	
	if (!get_int(argv[3], &(args.time_eat)))
		return (0);
	if (!get_int(argv[4], &(args.time_sleep)))
		return (0);
	if (argc == 5)
		args.n_eat = 2147483647;
	else if (argc == 6 && !get_int(argv[5], &(args.n_eat)))
		return (0);
	access_args(&args);
	return (1);
}

int	main(int argc, char **argv)
{
	pthread_t		*threads;
	// access_program_flag_sem에 대해 sem_wait을 main process의 monitor를 생성하기 전에 수행해야 한다.
	if (!parse_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_mutex_all())
		free_all(0, 1);
	if (!manage_threads(&threads))
		free_all(threads, 1);
	free_all(threads, 0);
	return (0);
}
