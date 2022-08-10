#include <stdlib.h>
#include <stdio.h> // remove
#include <string.h> // strerror
#include <errno.h> // errno codes
#include <readline/readline.h>
#include <readline/history.h>
#include "lexer.h"

int	main(void)
{
	char	*input;
	t_list	token_header;
	t_list	parsed_header;

	while (1)
	{
		input = readline(">");
		if (!input[0])
			continue ;
		if (!lexer(input, &token_header))
		{
			printf("%s\n", "syntax error");// this line should be replaced with error printer function
			continue ;
		}
		if (!parser(token_header.next, &parsed_header))
			printf("%s\n", "parser error");// this line should be replaced with error printer function
	}
	free(input);
	free_command_list(parsed_header.next);
	return (0);
}
