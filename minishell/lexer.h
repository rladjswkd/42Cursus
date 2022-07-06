#ifndef LEXER_H
# define LEXER_H
# define BLANKS	" \t"
# define CHAR_LREDIR	'<'
# define CHAR_RREDIR	'>'
# define CHAR_SQUOTE	'\''
# define CHAR_DQUOTE	'\"'
# define CHAR_PIPEOR	'|'
# define CHAR_LBRACKET	'('
# define CHAR_RBRACKET	')'
# define CHAR_AND	'&'
typedef	struct	s_list
{
	void	*data;
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
typedef enum	e_char
{
	LREDIR,
	RREDIR,
	SQUOTE,
	DQUOTE,
	PIPEOR,
	LBRACKET,
	RBRACKET,
	AND,
	BLANK
}	t_char;
#endif
