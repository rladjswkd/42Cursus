#ifndef TOKEN_H
# define TOKEN_H
# include "structure_token.h"
# include "structure_linked_list.h"
# include "type_token.h"

t_token	*get_token(t_list *token_list);
int	get_token_type(t_list *token_list);
int	create_token(t_list **token_list, char *str, int len, int types);
#endif