#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
    int		len_s1;
    int		len_s2;
    int		i;
    char	*output;

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    output = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!output)
        return (0);
    ft_strlcpy(output, s1, len_s1 + 1);
    ft_strlcpy(output + len_s1, s2, len_s2 + 1);
    return (output);
}