#include <stdio.h>
#include <string.h>
#define S "abc"
#define T "abc"
int	main(void)
{
	printf("%p\n", S);
	printf("%p\n", S);
	printf("%d\n", S - strchr(S, 'a'));
	printf("%p\n", T);
	printf("%p\n", T);
	return (0);
}
