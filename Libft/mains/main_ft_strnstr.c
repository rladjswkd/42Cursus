#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	const char	haystack[100] = "jkldddjklddd";
	const char	needle[100] = "ddd";
	const char	needle2[100] = "ccc";
	printf("%p\n", strnstr(haystack, needle, 3));
	printf("%p\n", ft_strnstr(haystack, needle, 3));
	printf("%p\n", strnstr(haystack, needle, 4));
	printf("%p\n", ft_strnstr(haystack, needle, 4));
	printf("%p\n", strnstr(haystack, needle, 5));
	printf("%p\n", ft_strnstr(haystack, needle, 5));
	printf("%p\n", strnstr(haystack, needle, 6));
	printf("%p\n", ft_strnstr(haystack, needle, 6));
	printf("%p\n", strnstr(haystack, needle, 12));
	printf("%p\n", ft_strnstr(haystack, needle, 12));
	printf("%p\n", strnstr(haystack, needle2, 1200));
	printf("%p\n", ft_strnstr(haystack, needle2, 1200));
	return (0);
}
