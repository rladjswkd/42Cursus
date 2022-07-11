#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes
#include <readline/readline.h>
#include <readline/history.h>

int	is_delimiter(char *s)
{
	char	c1;
	char	c2;

	c1 = *s;
	c2 = *(s + 1);
	return (c1 == CHAR_LREDIR || c1 == CHAR_RREDIR || c1 == CHAR_VERBAR
			|| c1 == CHAR_LBRACKET || c1 == CHAR_RBRACKET
			|| c1 == CHAR_SPACE || c1 == CHAR_TAB
			|| (c1 == CHAR_AMPERSAND && c2 == CHAR_AMPERSAND));
}

int	is_quote(char c)
{
	return (c == CHAR_SQUOTE || c == CHAR_DQUOTE);
}

int	extract_normal(char *str, int *types)
{
	int	len;

	*types = TOKEN_NORMAL;
	len = 0;
	while (str[len] && !(is_delimiter(&(str[len])) || is_quote(str[len])))
		len++;
	if (is_quote(str[len]))
		*types |= TOKEN_CONCAT;
	return (len);
}

int	extract_redir(char *str, int *types)
{
	*types = TOKEN_REDIR;
	if (*str != *(str + 1))
		return (1);
	if (*str == CHAR_LREDIR)
		*types |= TOKEN_HEREDOC;
	return (2);
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
	*types = TOKEN_LBRACKET;
	if (*str == CHAR_RBRACKET)
		*types = TOKEN_RBRACKET;
	return (1);
}

int	extract_logical_pipe(char *str, int *types)
{
	if (*str == CHAR_VERBAR && *(str + 1) != CHAR_VERBAR)
	{
		*types = TOKEN_PIPE;
		return (1);
	}
	*types = TOKEN_LOGICAL;
	return (2);
}

int	ignore_blank(char *str, int *types)
{
	int	len;

	*types = TOKEN_IGNORE;
	len = 0;
	while (str[len] == CHAR_SPACE || str[len] == CHAR_TAB)
		len++;
	return (len);
}

int	get_index(char c1, char c2)
{
	return ((c1 == CHAR_LREDIR || c1 == CHAR_RREDIR) * 1
			| (c1 == CHAR_SQUOTE || c1 == CHAR_DQUOTE) * 2
			| (c1 == CHAR_LBRACKET || c1 == CHAR_RBRACKET) * 3
			| ((c1 == CHAR_AMPERSAND && c2 == CHAR_AMPERSAND)
				|| c1 == CHAR_VERBAR) * 4
			| (c1 == CHAR_SPACE || c1 == CHAR_TAB) * 5);
}

int	create_token(t_list **token, char *str, int len, int types)
{
	if (types & TOKEN_IGNORE)
		return (1);
	if (len < 0)
		return (0);
	*token = (t_list *)malloc(sizeof(t_list));
	if (!(*token))
		return (0);
	(*token)->node = (t_token *)malloc(sizeof(t_token));
	if (!((*token)->node))
		return (0);
	len -= (types & TOKEN_SQUOTE || types & TOKEN_DQUOTE) << 2;
	str += types & TOKEN_SQUOTE || types & TOKEN_DQUOTE;
	((t_token *)(*token)->node)->data = (char *)malloc(len + 1);
	if (!(((t_token *)(*token)->node)->data))
		return (0);
	(((t_token *)(*token)->node)->data)[len] = 0;
	while (len--)
		(((t_token *)(*token)->node)->data)[len] = str[len];
	((t_token *)((*token)->node))->types = types;
	return (1);
}

int	tokenize_input(char *str, t_list *token_header)
{
	int	len;
	int	types;
	t_list	*cur;
	static int	(*len_fp[6])(char *, int *) = {
		&extract_normal, &extract_redir,
		&extract_quote,	&extract_bracket,
		&extract_logical_pipe, &ignore_blank};
	
	while (*str)
	{	
		len = (len_fp[get_index(*str, *(str + 1))])(str, &types);
		if (!create_token(&cur, str, len, types))
			return (0);
		if (!(types & TOKEN_IGNORE))
		{
			token_header->next = cur;
			token_header = token_header->next;
		}
		types = 0;
		str += len;
	}
	return (1);
}

int	syntax_check(t_list *token_list)
{
}

int	lexer(char *input, t_list *token_header)
{
	if (!tokenize_input(input, token_header))
		return (0); // set error message using singleton
	if (!syntax_check(token_header->next))
		return (0); // set error message using singleton for each syntax error type
	return (1);
}

int	main(void)
{
	t_list	token_header;
	char	*input;
	int	error;

	input = readline(">"); //while readline
	check_error(lexer(input, &token_header));
		return (0);
	return (0);
}
