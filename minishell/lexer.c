#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes

int	is_delimiter(char *str)
{
	char	c;

	c = *str;
	return (c == CHAR_LREDIR || c == CHAR_RREDIR || c == CHAR_VERBAR
			|| c == CHAR_LBRACKET || c == CHAR_RBRACKET
			|| c == CHAR_SPACE || c == CHAR_TAB
			|| (c == CHAR_AMPERSAND && *(str + 1) == CHAR_AMPERSAND));
}

int	extract_redir(char *str, int *types)
{
	char	c;

	return (1);
}


int	extract_quote(char *str, int *types)
{
	char	quote;
	int	len;

	quote = *str;
	len = 1;
	*types = TOKEN_NORMAL | TOKEN_DQUOTE;
	if (quote == CHAR_SQUOTE)
		*types = TOKEN_NORMAL | TOKEN_SQUOTE;
	while (*(++str) && *str != quote)
		len++;
	if (!(*str))
		return (-1);
	if (!is_delimiter(&(str[++len])))
		*types |= TOKEN_CONCAT;
	return (len);
}

int	extract_bracket(char *str, int *types)
{
}

int	extract_logic_and(char *str, int *types)
{
}

int	ignore_blacks(char *str, int *types)
{
}

int	get_char(char cur, char next)
{
	return ((cur == CHAR_LREDIR || cur == CHAR_RREDIR) * 1
			| (cur == CHAR_SQUOTE || cur == CHAR_DQUOTE) * 2
			| (cur == CHAR_VERBAR) * 4
			| (cur == CHAR_LBRACKET) * 5
			| (cur == CHAR_RBRACKET) * 6
			| (cur == CHAR_AMPERSAND) * 7
			| (cur == CHAR_SPACE || cur == CHAR_TAB) * 8);
}

int	create_token(t_list **token, char *str, int len, int types)
{
	char	*data_str;
	int	i;

	if (types & TOKEN_IGNORE)
		return (1);
	*token = (t_list *)malloc(sizeof(t_list *));
	if (!(*token))
		return (0);
	(*token)->node = (t_token *)malloc(sizeof(t_token));
	if ((*token)->node)
		return (0);
	data_str = (char *)malloc(len);
	if (!data_str)
		return (0);
	i = -1;
	while (++i < len)
		data_str[i] = s[i];
	((t_token *)token->node)->data = data_str;
	((t_token *)token->node)->types = types;
	return (1);
}

int	tokenize_input(char *input, t_list **token_list)
{
	int	len;
	int	types;
	t_list	*cur;
	int	(len_fp[10])(char *, int *);
	int	flag;

	cur = *token_list;
	while (*str)
	{	
		len = (len_fp[get_char(*str)])(str, &types);
		if (len < 0)
			return (0);
		flag = types | TOKEN_SQUOTE || types | TOKEN_DQUOTE;
		if (!create_token(&cur, str + flag, len - (flag << 1), types))
			return (0);
		if (!(types & TOKEN_IGNORE))
			cur = cur->next;
		types = 0;
		str += len;
	}
	return (1);
}

int	lexer(char *input, t_list **token_list)
{
	if (!tokenize_input(input, &token_list))
		return (0);//return (free_lexer(input, *token_list)); 1. free input 2. free data if data is "not null" before token and return 0
	free(input); // lexer is successfully done
	return (1);
}

int	main(void)
{
	t_list	*token_list;
	char	*input;

	// readline, while
	if (!lexer(input, &token_list))
		return (EXIT_FAILURE);// print strerr(ENOMEM)
	// 1. check if lexer returns 0 and print error (errno)
	return (0);
}
