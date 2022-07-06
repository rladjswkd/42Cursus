#include "lexer.h"
#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes

int	get_char(char cur, char next)
{
	return ((cur == CHAR_LREDIR)
			| (cur == CHAR_RREDIR) * 2
			| (cur == CHAR_SQUOTE) * 3
			| (cur == CHAR_DQUOTE) * 4
			| (cur == CHAR_PIPEOR) * 5
			| (cur == CHAR_LBRACKET) * 6
			| (cur == CHAR_RBRACKET) * 7
			| (cur == CHAR_AND) * 8
			| (cur == ' ' || c == '\t') * 9);
}

int	tokenize_input(char *input, t_list **token_list)
{
	int	i;
	int	len;
	int	token_types;
	t_list	*current;
	
	i = 0;
	len = 0;
	current = *token_list;
	while (input[i])
	{
		len = (*len_func_ptrs[get_char(input[i])])(&token_types);
		if (!create_token(&current, len))
			return (0);
		if (!set_token(current, input[i], len, token_types))
			return (0);
		token_types = 0;
		i += len;
	}
	return (1);
}

int	lexer(char *input, t_list **token_list)
{
	if (!tokenize_input(input, &token_list))
		return (free_token_and_input(input)); // 1. free input 2. free data if data is "not null" before token and return 0
	free(input); // lexer is successfully done
	return (1);
}

int	main(void)
{
	t_list	*token_list;

	// 1. check if lexer returns 0 and print error (errno)
	return (0);
}
