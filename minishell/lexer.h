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
typedef struct  s_command
{
        t_list  *args;
        t_list  *redir;
        int     type;
}       t_command;
typedef struct  s_compound
{
        t_list  *list;
        int     type;
}       t_compound;
typedef enum	e_token_flag
{
	TOKEN_NORMAL = 1,
	TOKEN_REDIR = 2,
	TOKEN_HEREDOC = 4,
	TOKEN_REDIRARG = 8,
	TOKEN_SQUOTE = 16,
	TOKEN_DQUOTE = 32,
	TOKEN_CONCAT = 64,
	TOKEN_PIPE = 128,
	TOKEN_LBRACKET = 256,
	TOKEN_RBRACKET = 512,
	TOKEN_LOGICAL = 1024,
	TOKEN_WILDCARD = 2048,
	TOKEN_IGNORE = 4096
}	t_token_flag;
typedef enum	e_command_type
{
	SIMPLE_NORMAL = 1,
	SIMPLE_PIPE = 2,
	SIMPLE_LBRACKET = 4,
	SIMPLE_RBRACKET = 8,
	SIMPLE_AND = 16,
	SIMPLE_OR = 32,
	COMPOUND_PIPELINE = 64,
	COMPOUND_SUBSHELL = 128
}	t_command_type;

#endif
