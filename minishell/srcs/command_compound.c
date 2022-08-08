int	get_compound_type(t_list *parsed)
{
	return (((t_compound *)(parsed->node))->type);
}

t_compound	*get_compound(t_list *parsed)
{
	return ((t_compound *)(parsed->node));
}
