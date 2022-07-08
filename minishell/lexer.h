#ifndef LEXER_H
# define LEXER_H
# define CHAR_SPACE	' '
# define CHAR_TAB	'\t'
# define CHAR_LREDIR	'<'
# define CHAR_RREDIR	'>'
# define CHAR_SQUOTE	'\''
# define CHAR_DQUOTE	'\"'
# define CHAR_VERBAR	'|'
# define CHAR_LBRACKET	'('
# define CHAR_RBRACKET	')'
# define CHAR_AMPERSAND	'&'
typedef	struct	s_list
{
	void	*node;
	struct s_list	*next;
}	t_list;
typedef struct	s_token
{
	char	*data;
	int	types;
}	t_token;
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
	TOKEN_LOGICAL,
	TOKEN_WILDCARD,
	TOKEN_IGNORE
}	t_token_flag;
#endif
