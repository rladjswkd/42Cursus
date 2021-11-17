#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	const unsigned char	arr[100] = "abadefg";
	const unsigned char brr[100] = "abcdeff";
	printf("%d\n", memcmp(arr, brr, 3));
	printf("%d\n", ft_memcmp(arr, brr, 3));
	printf("%d\n", memcmp(arr, brr, 7));
	printf("%d\n", ft_memcmp(arr, brr, 7));
	return (0);
}
