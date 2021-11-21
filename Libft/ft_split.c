#include "libft.h"
static int	count_words(char const *s)
{
	int	cnt;
	int	start;
	int	end;

	cnt = 0;
	start = 0;
	end = -1;
	while (s[++end])
	{
		if (s[end] == c && start < end)
		{
			start = end + 1;
			cnt++;
		}
	}
	return (cnt + (start != end));
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		start;
	int		end;
	int		i;

	output = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (output == 0)
		return (0);
	start = 0;
	end = -1;
	i = 0;
	while (++end)
	{
		if (s[end] == c && start < end)
		{
			output[i] = (char *)malloc(sizeof(char) * (end - start + 1));
			if (output[i] == 0)
				return (0);
			ft_strlcpy(output[i++], s + start, end - start + 1);
			start = end + 1;
		}
	}
	if (start != end)
	{
		output[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (output[i] == 0)
			return (0);
		ft_strlcpy(output[i++], s + start, end - start + 1);
	}
	output[i] = 0;
	return (output);
}
