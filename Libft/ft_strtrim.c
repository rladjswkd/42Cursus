#include "libft.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*output;
	int		len_output;

	start = -1;
	end = len(s1);
	// ft_strchr 문을 while문의 조건문으로 넣고 while문의 body를 {}로 해도 norminette 통과하는지 확인하기!
	while (s1[++start])
	{
		if (ft_strchr(set, s1[start]) == 0)
			break;
	}
	while (s1[--end] && start <= end)
	{
		if (ft_strchr(set, s1[end]) == 0)
			break;
	}
	if (end < start)
		len_output = 1;
	else
		len_output = end - start + 2;
	output = (char *)malloc(sizeof(char) * len_output);
	if (output == 0)
		return (0);
	ft_strlcpy(output, s1 + start, len_output);
	return (output);
}