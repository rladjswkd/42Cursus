#include "test.h"

// printf는 thread-safe이고, 이건 프로세스에도 적용된다.
int	main(void)
{
	int	n = 20;
	int	i = -1;
	pid_t	pid;

	while (++i < n)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("%s\n", "this is multiprocess printf test.");
			exit(0);
		}
		printf("%s %d\n", "this is main process ", i + 1);
	}
	return (0);
}
