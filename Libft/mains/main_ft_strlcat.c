#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <stdlib.h>
int	main(void)
{
	char	*nn;
	int		i;

	nn = (char *)malloc(sizeof(10));
	i = -1;
	while (++i < 5)
		nn[i] = 'a' + i;
	nn[i] = '\0';

	printf("%lu\n", strlcat((void *)0, "hello", 0));
//	printf("%lu\n", strlcat((void *)0, "hello", 3)); segfault occurs
//	printf("%lu\n", strlcat((void *)0, "hello", 5));
//	printf("%lu\n", strlcat((void *)0, "hello", 10));
//	printf("%lu\n", strlcat(nn, (void *)0, 0));
//	printf("%lu\n", strlcat(nn, (void *)0, 3));
//	printf("%lu\n", strlcat(nn, (void *)0, 5));
//	printf("%lu\n", strlcat(nn, (void *)0, 10));
	printf("%lu\n", strlcat(nn, "hello", 0));
//	printf("%s\n", nn); concatenation not occurs
	printf("%lu\n", strlcat(nn, "hello", 3));
//	printf("%s\n", nn); concatenation not occurs
//	printf("%lu\n", strlcat(nn, "hello", 5));
	printf("%s\n", nn);
	printf("%lu\n", strlcat(nn, "hello", 10));
	printf("%s\n", nn);

//	printf("%lu\n", ft_strlcat((void *)0, "hello", 0));
	return (0);
}
