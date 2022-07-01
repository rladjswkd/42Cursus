#ifndef LEXER_H
# define LEXER_H
# define BLANK	" \t"
# define AND	"&"
# define OR	"|"
# define REDIR	"<>"
# define QUOTE	"\"\'"
# define BRACKET "()"
typedef	struct	s_list
{
	void	*node;
	struct s_list	*next;
}	t_list;
typedef enum	e_token_flag
{
	TOKEN_NORMAL,
	TOKEN_REDIR,
	TOKEN_HEREDOC,
	TOKEN_FILENAME,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_CONCAT,
	TOKEN_PIPE,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_ANDOR,
	TOKEN_WILDCARD
}	t_token_flag;
typedef enum	e_state
{
	STATE_NORMAL,
	STATE_LREDIR,
	STATE_LDREDIR,
	STATE_RREDIR,
	STATE_RDREDIR,
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_PIPE,
	STATE_LBRACKET,
	STATE_RBRACKET,
	STATE_DAND,
	STATE_DOR,
	STATE_BLANK
}	t_state;
#endif
