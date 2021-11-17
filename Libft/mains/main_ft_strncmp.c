#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	const char	charr[100] = "abcdef";
	const char	chbrr[100] = "abcdegf";
	printf("%d\n", strncmp(charr, chbrr, 6));
	printf("%d\n", ft_strncmp(charr, chbrr, 6));
	printf("%d\n", strncmp(charr, chbrr, 5));
	printf("%d\n", ft_strncmp(charr, chbrr, 5));
	printf("%d\n", strncmp(charr, chbrr, 10));
	printf("%d\n", ft_strncmp(charr, chbrr, 10));
	return (0);
}
