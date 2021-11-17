#include "libft.h"
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;

	i = 0;
	s_temp = (unsigned char *)s;
	while (i < n)
		s_temp[i++] = 0;
}
