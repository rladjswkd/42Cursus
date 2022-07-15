#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes
#include <readline/readline.h>
#include <readline/history.h>

int	is_delimiter(char *s)
{
	char	c;

	c = *s;
	return (c == CHAR_LREDIR || c == CHAR_RREDIR || c == CHAR_VERBAR
		|| c == CHAR_LBRACKET || c == CHAR_RBRACKET
		|| c == CHAR_SPACE || c == CHAR_TAB
		|| (c == CHAR_AMPERSAND && *(s + 1) == CHAR_AMPERSAND));
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
	int		len;

	quote = *str;
	len = 1;
	*types = TOKEN_NORMAL | TOKEN_DQUOTE;
	if (quote == CHAR_SQUOTE)
		*types = TOKEN_NORMAL | TOKEN_SQUOTE;
	while (*(++str) && *str != quote)
		len++;
	if (!(*str))
		return (-1);
	if (str[len] && !is_delimiter(&(str[len])))
		*types |= TOKEN_CONCAT;
	return (len + 1);
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

t_token	*get_token(t_list *token_list)
{
	return ((t_token *)(token_list->node));
}

int	get_token_type(t_list *token_list)
{
	return (((t_token *)(token_list->node))->types);
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
	len -= (!!(types & (TOKEN_SQUOTE | TOKEN_DQUOTE))) << 1;
	str += !!(types & (TOKEN_SQUOTE | TOKEN_DQUOTE));
	((t_token *)(*token)->node)->data = (char *)malloc(len + 1);
	if (!(get_token(*token)->data))
		return (0);
	(get_token(*token)->data)[len] = 0;
	while (len--)
		(get_token(*token)->data)[len] = str[len];
	(get_token(*token))->types = types;
	return (1);
}

int	tokenize_input(char *str, t_list *token_header)
{
	int			len;
	int			types;
	t_list		*cur;
	static int	(*len_fp[6])(char *, int *) = {
		&extract_normal, &extract_redir,
		&extract_quote,	&extract_bracket,
		&extract_logical_pipe, &ignore_blank
	};

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
	token_header->next = 0;
	return (1);
}

int	is_redir_error(int curr, int next)
{
	return (curr & TOKEN_REDIR && !(next & TOKEN_NORMAL));
}

int	is_pipe_logical_error(int curr, int next)
{
	return (curr & (TOKEN_PIPE | TOKEN_LOGICAL)
		&& !(next & (TOKEN_NORMAL | TOKEN_REDIR | TOKEN_LBRACKET)));
}

int	is_bracket_error(int curr, int next)
{
	return ((curr & TOKEN_LBRACKET
			&& !(next & (TOKEN_NORMAL | TOKEN_REDIR)))
		|| (curr & TOKEN_RBRACKET
			&& next && !(next & (TOKEN_PIPE | TOKEN_LOGICAL))));
}

int	is_normal_error(int curr, int next)
{
	return (curr & TOKEN_NORMAL && next && next & TOKEN_LBRACKET);
}

int	syntax_check(t_list *token_list)
{
	int	curr;
	int	next;
	int	pair;

	if (get_token_type(token_list)
		& (TOKEN_PIPE | TOKEN_LOGICAL | TOKEN_RBRACKET))
		return (0);
	pair = 0;
	while (token_list)
	{
		curr = get_token_type(token_list);
		next = 0;
		if (token_list->next)
			next = get_token_type(token_list->next);
		if (is_redir_error(curr, next) || is_normal_error(curr, next)
			|| is_pipe_logical_error(curr, next)
			|| is_bracket_error(curr, next))
			return (0);
		pair += curr == TOKEN_LBRACKET;
		pair -= curr == TOKEN_RBRACKET;
		if (pair < 0)
			return (0);
		token_list = token_list->next;
	}
	return (pair == 0);
}


void	mask_redirarg_type(t_list *token_list)
{
	while (token_list)
	{
		if (get_token_type(token_list) & TOKEN_REDIR)
		{
			token_list = token_list->next;
			get_token(token_list)->types |= TOKEN_REDIRARG;
			while (get_token_type(token_list) & TOKEN_CONCAT)
			{
				token_list = token_list->next;
				get_token(token_list)->types |= TOKEN_REDIRARG;
			}
		}
		token_list = token_list->next;
	}
}

int	get_command_type(t_list *parsed)
{
	return (((t_command *)(parsed->node))->type);
}

t_command	*get_command(t_list *parsed)
{
	return ((t_command *)(parsed->node));
}

int	create_command(t_list *parsed, int type)
{
	parsed = (t_list *)malloc(sizeof(t_list));
	if (!parsed)
		return (0);
	parsed->node = (t_command *)malloc(sizeof(t_command));
	if (!(parsed->node))
		return (0);
	get_command(parsed)->type = type;
	return (1);
}

int	find_command_type(t_list *token_list)
{
	int	type;

	type = get_token_type(token_list);
	if (type & (TOKEN_NORMAL | TOKEN_REDIR))
		return (SIMPLE_NORMAL);
	else if (type & TOKEN_PIPE)
		return (SIMPLE_PIPE);
	else if (type & TOKEN_LBRACKET)
		return (SIMPLE_LBRACKET);
	else if (type & TOKEN_RBRACKET)
		return (SIMPLE_RBRACKET);
	else if (type & TOKEN_LOGICAL)
	{
		if ((get_token(token_list)->data)[0] == CHAR_AMPERSAND)
			return (SIMPLE_AND);
		return (SIMPLE_OR);
	}
	return (-1);
}

void	append_token(t_list **list, t_list *token)
{
	t_list	*current;

	if (!(*list))
	{
		*list = token;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = token;
}

void	parse_args_redirs(t_list *parsed, t_list **token_list)
{
	int	command;
	t_list	*token;

	while (find_command_type(*token_list) & SIMPLE_NORMAL)
	{
		command = get_command(parsed);
		token = *token_list;
		token_list = token_list->next;
		if (get_token_type(token_list) & (TOKEN_REDIR | TOKEN_REDIRARG))
			append_token(&(command->redirs), token);
		else
			append_token(&(command->args), token);
	}
}

int	parse_command(t_list *token_list, t_list *header)
{
	int	type;
	t_list	*token_ptr;

	while (token_list)
	{
		type = find_command_type(token_list);
		if (!create_command(header->next, type))
			return (0);
		if (type & SIMPLE_NORMAL)
			parse_args_redirs(header->next, &token_list);
		else
		{
			token_ptr = token_list;
			token_list = token_list->next;
			free(get_token(token_ptr)->data)
			free(token);
		}
		header = header->next;
	}
	return (1);
}

int	find_brackets(t_list *lst, t_list **l, t_list **r)
{
	int	type;

	while (lst)
	{
		type = get_command_type(lst);
		if (type == COMMAND_LBRACKET)
			*l = lst;
		else if (type == COMMAND_PIPELINE)
		{
			*l = 0;
			*r = 0;
		}
		else if (*l && type == COMMAND_RBRACKET)
		{
			*r = lst;
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	make_subshell(t_list **parsed, int *flag)
{
	t_list	*lbracket;
	t_list 	*rbracket;

	if (!find_brackets(&lbracket, &rbracket))
		return (0);
	
	return (1);
}

int	make_pipeline(t_list **parsed, int *flag)
{

	return (1);
}

int	make_compound(t_list *parsed)
{
	int	flag;

	flag = 1;
	while (flag)
		if (!make_subshell(&parsed, &flag)
				|| !make_pipeline(&parsed, &flag))
			return (0);
	return (1);
}

int	parser(t_list *token_list, t_list *parsed_header)
{
	if (!parse_command(token_list, parsed_header))
		return (0);
	if (!make_compound(parsed_header->next))
		return (0);
	return (1);
}

int	lexer(char *input, t_list *token_header)
{
	if (!tokenize_input(input, token_header))
		return (0); // set error message using singleton
	if (!syntax_check(token_header->next))
		return (0); // set error message using singleton for each syntax error type
	mask_redirarg_type(token_header->next);
	return (1);
}

void	print_token_content(t_list *token_list) //remove
{
	int	types;

	while (token_list)
	{
		types = get_token_type(token_list);
		printf("\n");
		printf("token content:\t%s\n", ((t_token *)(token_list->node))->data);
		printf("token types:\t");
		if (types & TOKEN_NORMAL)
			printf("%s ", "TOKEN_NORMAL");
		if (types & TOKEN_REDIR)
			printf("%s ", "TOKEN_REDIR");
		if (types & TOKEN_HEREDOC)
			printf("%s ", "TOKEN_HEREDOC");
		if (types & TOKEN_REDIRARG)
			printf("%s ", "TOKEN_REDIRARG");
		if (types & TOKEN_SQUOTE)
			printf("%s ", "TOKEN_SQUOTE");
		if (types & TOKEN_DQUOTE)
			printf("%s ", "TOKEN_DQUOTE");
		if (types & TOKEN_CONCAT)
			printf("%s ", "TOKEN_CONCAT");
		if (types & TOKEN_PIPE)
			printf("%s ", "TOKEN_PIPE");
		if (types & TOKEN_LBRACKET)
			printf("%s ", "TOKEN_LBRACKET");
		if (types & TOKEN_RBRACKET)
			printf("%s ", "TOKEN_RBRACKET");
		if (types & TOKEN_LOGICAL)
			printf("%s ", "TOKEN_LOGICAL");
		if (types & TOKEN_WILDCARD)
			printf("%s ", "TOKEN_WILDCARD");
		if (types & TOKEN_IGNORE)
			printf("%s ", "TOKEN_IGNORE");
		printf("\n");
		token_list = token_list->next;
	}
}

int	main(void)
{
	char	*input;
	t_list	token_header;
	t_list	parsed_header;
	int		error;

	while (1)
	{
		input = readline(">");
		if (!lexer(input, &token_header))
			printf("%s\n", "syntax error");
		else //remove
			print_token_content(token_header.next);
		if (!parser(token_header.next, &parsed_header))
			printf("%s\n", "parser error");
	}
	return (0);
}
