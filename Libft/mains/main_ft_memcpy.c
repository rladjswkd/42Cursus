#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <stdlib.h>
int	main(void)
{
	char	*nn;

	nn = (char *)malloc(sizeof(10));
	printf("%p\n", memcpy((void *)0, (void *)0, 0));
	printf("%p\n", ft_memcpy((void *)0, (void *)0, 0));
	printf("%p\n", memcpy((void *)nn, (void *)0, 0));
	printf("%p\n", ft_memcpy((void *)nn, (void *)0, 0));
	printf("%p\n", memcpy((void *)0, (void *)nn, 0));
	printf("%p\n", ft_memcpy((void *)0, (void *)nn, 0));
	printf("%p\n", memcpy((void *)0, (void *)0, 10));
	printf("%p\n", ft_memcpy((void *)0, (void *)0, 10));
//	printf("%p\n", memcpy((void *)nn, (void *)0, 10)); segfault occurs
//	printf("%p\n", ft_memcpy((void *)nn, (void *)0, 10));
//	printf("%p\n", memcpy((void *)0, (void *)nn, 10));
//	printf("%p\n", ft_memcpy((void *)0, (void *)nn, 10));
	return (0);
}
