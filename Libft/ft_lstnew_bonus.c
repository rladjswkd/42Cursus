#include "libft_bonus.h"
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == 0)
		return ((t_list *)0);
	node->content = content;
	node->next = (t_list *)0;
	return (node);
}
