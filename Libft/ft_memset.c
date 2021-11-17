#include "libft.h"
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	*b_temp;

	i = 0;
	b_temp = (unsigned char *)b;
	while (i < len)
		b_temp[i++] = (unsigned char)c;
	return ((void *)b);
}
