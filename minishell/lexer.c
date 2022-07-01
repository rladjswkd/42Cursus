#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove

int	get_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*find_char(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

int	trim_both_end(char *str, char *trimed)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = get_len(str) - 1;
	while (find_char(BLANK, str[start]))
		start++;
	while (find_char(BLANK, str[end]))
		end--;
	if (start > end)
		trimed = (char *)malloc(1);
	else
		trimed = (char *)malloc(end - start + 2);
	if (!trimed)
		return (0);
	i = 0;
	while (start <= end)
		trimed[i++] = str[start++];
	trimed[i] = 0;
	free(str);
	return (1);
}

int	get_state(char *trimed, int state, int *i)
{
	if (find_char(AND, trimed[*i]))
		
	else if (find_char(OR, trimed[*i]))
		
	else if (find_char(REDIR, trimed[*i]))
		
	else if (find_char(QUOTE, trimed[*i]))
		
	else if (find_char(BRACKET, trimed[*i]))
		
	else if (find_char(BLANK, trimed[*i]))
}

int	analyze_token(char *trimed, t_list *token_list)
{
	int	i;
	int	state;

	i = -1;
	while (trimed[++i])
	{

	}
	free(trimed);
	return (1);
}

int	lexer(char *str, t_list *token_list)
{
	char	*trimed;
	// 1. 좌, 우 trim
	if (!trim_both_end(str, trimed))
		return (0);
	if (!analyze_token(trimed, token_list))
		return (0);
}

int	main(void)
{
	return (0);
}
