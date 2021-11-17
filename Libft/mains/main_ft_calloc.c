#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
int	main(void)
{
	int	*pa;
	int	*pb;

	int	i;

	i = -1;
	pa = (int *)calloc(sizeof(int), 10);
	pb = (int *)ft_calloc(sizeof(int), 10);
	while (++i < 10)
		printf("%d, %d\n", pa[i], pb[i]);
	return (0);
}
