int	parser(t_list *token_list, t_list *parsed_header)
{
	if (!parse_simple(token_list, parsed_header))
		return (0);
	if (!parse_compound(&(parsed_header->next)))
		return (0);
	return (1);
}