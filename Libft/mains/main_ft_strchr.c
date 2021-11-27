#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	char	str[4] = {"abc"};
//	printf("%p\n", strchr((void *)0, 0)); segfault occurs
//	printf("%p\n", ft_strchr((void *)0, 0));
	printf("%p\n", strchr("abc", 0));
	printf("%p\n", ft_strchr("abc", 0));
	printf("%p\n", strchr("abc", 1));
	printf("%p\n", ft_strchr("abc", 1));
	return (0);
}
