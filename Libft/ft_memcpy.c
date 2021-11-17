#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_temp; 
	unsigned char	*src_temp;

	i = -1;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (++i < n)
		dst_temp[i] = src_temp[i];
	return ((void *)dst);
}
