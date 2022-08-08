t_command	*get_command(t_list *parsed)
{
	return ((t_command *)(parsed->node));
}

int	get_command_type(t_list *parsed)
{
	return (((t_command *)(parsed->node))->type);
}

int	create_command(t_list **neu, int type)
{
	if (!malloc_wrapper(sizeof(t_list), (void **)neu))
		return (0);
	if (!malloc_wrapper(sizeof(t_command), (void **)(&(*neu)->node)))
		return (0);
	get_command(*neu)->type = type;
	return (1);
}

void	get_prev_command(t_list *parsed, t_list *node, t_list **prev)
{
	*prev = 0;
	if (parsed != node)
		while (parsed->next && parsed->next != node)
			parsed = parsed->next;
	*prev = parsed;
}