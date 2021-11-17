#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	char	arr[100] = "abcdefc";
	printf("%p\n", memchr(arr, 'c', 2));
	printf("%p\n", ft_memchr(arr, 'c', 2));
	printf("%p\n", memchr(arr, 'c', 3));
	printf("%p\n", ft_memchr(arr, 'c', 3));
	printf("%p\n", memchr(arr, 'c', 4));
	printf("%p\n", ft_memchr(arr, 'c', 4));
	return (0);
}
