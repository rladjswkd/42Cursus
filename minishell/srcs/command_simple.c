int	get_simple_type(t_list *parsed)
{
	return (((t_simple *)(parsed->node))->type);
}

t_simple	*get_simple(t_list *parsed)
{
	return ((t_simple *)(parsed->node));
}