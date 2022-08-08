void	append_back(t_list **list, t_list *neu)
{
	t_list	*temp;

	if (!(*list))
	{
		*list = neu;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = neu;
}