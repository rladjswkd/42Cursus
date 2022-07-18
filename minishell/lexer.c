#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes
#include <readline/readline.h>
#include <readline/history.h>
void	free_compound(t_list *);
void	free_command(t_list *);

/*
int	malloc_wrapper(size_t size, void **ptr)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (0);
	return (1);
}
*/
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

int	create_token(t_list **token_list, char *str, int len, int types)
{
	if (types & TOKEN_IGNORE)
		return (1);
	if (len < 0)
		return (0);
	*token_list = (t_list *)malloc(sizeof(t_list));
	if (!(*token_list))
		return (0);
	(*token_list)->node = (t_token *)malloc(sizeof(t_token));
	if (!get_token(*token_list))
		return (0);
	len -= (!!(types & (TOKEN_SQUOTE | TOKEN_DQUOTE))) << 1;
	str += !!(types & (TOKEN_SQUOTE | TOKEN_DQUOTE));
	get_token(*token_list)->data = (char *)malloc(sizeof(len + 1));
	if (!(get_token(*token_list)->data))
		return (0);
	(get_token(*token_list)->data)[len] = 0;
	while (len--)
		(get_token(*token_list)->data)[len] = str[len];
	get_token(*token_list)->types = types;
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
	int	lmask;
	int	rmask;

	lmask = TOKEN_NORMAL | TOKEN_REDIR | TOKEN_LBRACKET;
	rmask = TOKEN_PIPE | TOKEN_LOGICAL | TOKEN_RBRACKET;
	return ((curr & TOKEN_LBRACKET && !(next & lmask))
		|| (curr & TOKEN_RBRACKET && next && !(next & rmask)));
}

int	is_normal_error(int curr, int next)
{
	return (curr & TOKEN_NORMAL && next && next & TOKEN_LBRACKET);
}

int	is_error(int curr, int next, int *pair)
{
	*pair += curr == TOKEN_LBRACKET;
	*pair -= curr == TOKEN_RBRACKET;
	return (*pair < 0 || is_redir_error(curr, next)
			|| is_normal_error(curr, next)
			|| is_pipe_logical_error(curr, next)
			|| is_bracket_error(curr, next));
}

int	check_syntax(t_list *token_list)
{
	int		type;
	int		next;
	int		pair;
	t_list	*cur;

	if (get_token_type(token_list)
		& (TOKEN_PIPE | TOKEN_LOGICAL | TOKEN_RBRACKET))
		return (0);
	pair = 0;
	cur = token_list;
	while (cur)
	{
		type = get_token_type(cur);
		next = 0;
		if (cur->next)
			next = get_token_type(cur->next);
		if (is_error(type, next, &pair))
			return (0);
		cur = cur->next;
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

int	get_simple_type(t_list *parsed)
{
	return (((t_simple *)(parsed->node))->type);
}

t_simple	*get_simple(t_list *parsed)
{
	return ((t_simple *)(parsed->node));
}

int	get_compound_type(t_list *parsed)
{
	return (((t_compound *)(parsed->node))->type);
}

t_compound	*get_compound(t_list *parsed)
{
	return ((t_compound *)(parsed->node));
}

int	get_command_type(t_list *parsed)
{
	return (((t_command *)(parsed->node))->type);
}

t_command	*get_command(t_list *parsed)
{
	return ((t_command *)(parsed->node));
}

int	create_command(t_list **new, int type)
{
	*new = (t_list *)malloc(sizeof(t_list));
	if (!(*new))
		return (0);
	(*new)->node = (t_command *)malloc(sizeof(t_command));
	if (!((*new)->node))
		return (0);
	get_command(*new)->type = type;
	return (1);
}

int	find_simple_type(t_list *token_list)
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

void	append_token(t_list **simple, t_list *token)
{
	t_list	*current;

	if (!(*simple))
	{
		*simple = token;
		return ;
	}
	current = *simple;
	while (current->next)
		current = current->next;
	current->next = token;
}

void	parse_args_redirs(t_list *parsed, t_list **list)
{
	t_simple	*simple;
	t_list		*next;

	while (find_simple_type(*list) & SIMPLE_NORMAL)
	{
		simple = get_simple(parsed);
		next = (*list)->next;
		if (get_token_type(*list) & (TOKEN_REDIR | TOKEN_REDIRARG))
			append_token(&(simple->redirs), *list);
		else
			append_token(&(simple->args), *list);
		(*list)->next = 0;
		*list = next;
	}
}

void	free_token(t_list *token)
{
	free(get_token(token)->data);
	free(token);
}

void	free_token_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free_token(list);
		list = next;
	}
}

void	free_simple(t_list *list)
{
	t_simple	*simple;

	simple = get_simple(list);
	free_token_list(simple->args);
	free_token_list(simple->redirs);
	free(list->node);
	free(list);
}

void	free_compound(t_list *list)
{
	t_compound	*compound;

	compound = get_compound(list);
	while (compound->list)
	{
		free_command(compound->list);
		compound->list = compound->list->next;
	}
	free(compound->list);
	free(list);
}

void	free_command(t_list *list)
{
	t_command	*command;
	t_list		*next;

	command = get_command(list);
	if (command->type & SIMPLE_NORMAL)
		free_simple(list);
	else
		free_compound(list);
}
int	parse_simple(t_list *token_list, t_list *parsed_header)
{
	int	type;
	t_list	*token_ptr;
	t_list	*parsed;

	parsed = parsed_header->next;
	while (token_list)
	{
		type = find_simple_type(token_list);
		if (!create_command(&parsed, type))
			return (0);
		if (type & SIMPLE_NORMAL) // SIMPLE_NORMAL을 제외한 SIMPLE 들은 TOKEN이 free된다.
			parse_args_redirs(parsed, &token_list);
		else
		{
			token_ptr = token_list;
			token_list = token_list->next;
			free_token(token_ptr);
		}
		parsed = parsed->next;
	}
	return (1);
}

int	find_lbracket(t_list *parsed, t_list *rbracket, t_list **lbracket)
{
	int		type;

	*lbracket = 0;
	while (parsed && parsed != rbracket)
	{
		type = get_simple_type(parsed);
		if (type & SIMPLE_LBRACKET)
			*lbracket = parsed;
		if (*lbracket && type & SIMPLE_PIPE)
			*lbracket = 0;
		parsed = parsed->next;
	}
	return (*lbracket != 0);
}

int	find_rbracket(t_list *parsed, t_list **rbracket)
{
	t_list	*cur;

	cur = parsed;
	*rbracket = 0;
	while (cur)
	{
		if (get_simple_type(cur) & SIMPLE_RBRACKET)
		{
			*rbracket = cur;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

void	get_prev_command(t_list *parsed, t_list *node, t_list **prev)
{
	*prev = 0;
	if (parsed == node)
	{
		*prev = parsed; 
		return ;
	}
	while (parsed->next && parsed->next != node)
		parsed = parsed->next;
	*prev = parsed->next;
}

void	remove_brackets(t_list **parsed, t_list *l, t_list *r, t_list *new)
{
	t_list	*prev_l;
	t_list	*l_ptr;

	get_compound(new->node)->list = l->next;
	l_ptr = l;
	while (l_ptr->next && l_ptr->next != r)
		l_ptr = l_ptr->next;
	l_ptr->next = 0;
	l->next = 0;
	get_prev_command(*parsed, l, &prev_l);
	if (prev_l == l)
		*parsed = new;
	else
		prev_l->next = new;
	new->next = r->next;
	free_command(l);
	free_command(r);
}

int	process_subshell(t_list **parsed, t_list *r)
{
	t_list	*l;
	t_list	*new;

	if (!r || !find_lbracket(*parsed, r, &l))
		return (1);
	if (get_simple_type(l->next) & COMPOUND_SUBSHELL && l->next->next == r)
		return (0); // syntax error. ((...))
	if (!create_command(&new, COMPOUND_SUBSHELL))
		return (0);
	remove_brackets(parsed, l, r, new);
	return (1);
}

int	is_included_pipeline(t_list *parsed)
{
	static int	mask = 
		SIMPLE_NORMAL | COMPOUND_SUBSHELL | COMPOUND_PIPELINE;

	return (parsed && get_command_type(parsed) & mask
		&& parsed->next	&& get_command_type(parsed->next) & SIMPLE_PIPE
		&& parsed->next->next
		&& get_command_type(parsed->next->next) & mask);
}

void	find_pipeline(t_list *parsed, t_list **start, t_list **end)
{
	int	mask;

	*start = 0;
	*end = 0;
	while (parsed && (*start)->next != parsed)
	{
		if (is_included_pipeline(parsed))
			*start = parsed;
		parsed = parsed->next;
	}
	while (parsed && *end != parsed)
	{
		if (is_included_pipeline(parsed))
			parsed = parsed->next->next;
		else
			*end = parsed;
	}
}
/*
int	rearrange_pipeline(t_list **parsed, t_list *s, t_list *e, t_list *new)
{
	t_list	*prev_s;
	t_compound	*pipeline;
	t_list	*ptr;
	int	type;

	get_prev_command(*parsed, s, &prev_s);
	if (prev_s == s)
		*parsed = new;
	else
		prev_s->next = new;
	new->next = e->next;
	pipeline = get_compound(new);
	while (s != e->next)
	{
		type = get_command_type(s);
		ptr = s->next;
		if (type & SIMPLE_PIPE)
			free_command()
	}
}

int	process_pipeline(t_list **parsed)
{
	t_list	*start;
	t_list	*end;
	t_list	*new;

	find_pipeline(*parsed, &start, &end);
	if (!create_command(&new, COMPOUND_PIPELINE))
		return (0);
}

int	find_pipe(t_list *parsed)
{
	while (parsed)
	{
		if (get_command_type(parsed) & SIMPLE_PIPE)
			return (1);
		parsed = parsed->next;
	}
	return (0);
}

int	process_compound(t_list *parsed)
{
	int		flag;
	t_list	*rbracket;

	flag = find_rbracket(parsed, &rbracket) || find_pipe(parsed);
	while (flag)
	{
		if (!process_subshell(&parsed, rbracket)
			|| !process_pipeline(&parsed))
			return (0);
		flag = find_rbracket(parsed, &rbracket)
			|| find_pipe(parsed);
	}
	return (1);
}
*/
int	parser(t_list *token_list, t_list *parsed_header)
{
	if (!parse_simple(token_list, parsed_header))
		return (0);
//	if (!process_compound(parsed_header->next))
//		return (0);
	return (1);
}

int	lexer(char *input, t_list *token_header)
{
	t_list	*list;

	if (!tokenize_input(input, token_header))
		return (0); // set error message using singleton
	list = token_header->next;
	if (!check_syntax(list))
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
