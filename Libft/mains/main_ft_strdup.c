#include <string.h>
#include "libft.h"
#include <stdio.h>
int	main(void)
{
	char	src[100] = "world!";
	char	*p1 = strdup(src);
	char	*p2 = ft_strdup(src);
	int		i = 0;
	while (p1[i])
		printf("%c", p1[i++]);
	printf("\n");
	i = 0;
	while (p2[i])
		printf("%c", p2[i++]);

	return (0);
}

