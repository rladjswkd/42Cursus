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

int	ignore_blank(char *str, int *types)
{
	int	len;

	*types = TOKEN_IGNORE;
	len = 0;
	while (str[len] == CHAR_SPACE || str[len] == CHAR_TAB)
		len++;
	return (len);
}