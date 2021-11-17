#include <stdio.h>
#include "libft.h"
#include <string.h>
int	main(void)
{
	const char	arr[10] = "abcdeabcd";
	printf("%p\n", strrchr(arr, 'a'));
	printf("%p\n", ft_strrchr(arr, 'a'));
	printf("%d\n", strrchr(arr, 'f') == 0);
	printf("%d\n", ft_strrchr(arr, 'f') == 0);
	printf("%p\n", strrchr(arr, '\0'));
	printf("%p\n", ft_strrchr(arr, '\0'));
	return (0);
}
