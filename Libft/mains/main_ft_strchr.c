#include <stdio.h>
#include "libft.h"
#include <string.h>
int	main(void)
{
	const char	arr[10] = "abcdeabcd";
//	printf("%p\n", strchr(arr, 'a'));
//	printf("%p\n", ft_strchr(arr, 'a'));
	printf("%d\n", strchr(arr, 'f') == 0);
	printf("%d\n", ft_strchr(arr, 'f') == 0);
//	printf("%p\n", strchr(arr, '\0'));
//	printf("%p\n", ft_strchr(arr, '\0'));
	return (0);
}
