#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	*ft_memmove(void *dst, const void *src, size_t len);
int	main(void)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(5 * sizeof(char));
	while (i < 5)
	{
		dst[i] = (char)(97 + i);
		i++;
	}
	i = 0;
	memmove(dst + 2, dst, 3);
	while (i < 5)
		printf("%c", dst[i++]);
	printf("\n");
	i = 0;
	while (i < 5)
	{
		dst[i] = (char)(97 + i);
		i++;
	}
	ft_memmove(dst + 2, dst, 3);
	i = 0;
	while (i < 5)
		printf("%c", dst[i++]);
	return (0);
}
