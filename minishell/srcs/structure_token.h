#ifndef STRUCTURE_TOKEN_H
# define STRUCTURE_TOKEN_H
typedef struct s_token
{
	int		types;
	char	*data;
	int		heredoc_fd;
}			t_token;
#endif