#include "libft.h"
size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	src_len = 0; /*ft_strlen*/
	while (src[src_len])
		src_len++;
	return (src_len);
}
