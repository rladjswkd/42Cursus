#include "libft.h"
#include <stdio.h>
int	main(void)
{
	char	*p = "                  olol";
	char	c = ' ';
	char	**result = ft_split(p, c);
	while (*result)
		printf("%s\n", *(result++));
	return (0);
}
