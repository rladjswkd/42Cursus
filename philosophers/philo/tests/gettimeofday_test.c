#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	struct timeval	val;

	gettimeofday(&val, 0);
	printf("%ld\n", val.tv_sec);
	printf("%ld\n", val.tv_usec);
	return (0);
}
