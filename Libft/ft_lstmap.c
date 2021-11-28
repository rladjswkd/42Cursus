/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:33:12 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/28 23:48:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*current;
	t_list	*next;

	header = ft_lstnew((void *)0);
	if (!header)
		return ((t_list *)0);
	current = header;
	while (lst)
	{
		next = ft_lstnew((*f)(lst->content));
		if (!next)
		{
			ft_lstclear(&header, del);
			return ((t_list *)0);
		}
		current->next = next;
		current = current->next;
		lst = lst->next;
	}
	next = header->next;
	free(header);
	return (next);
}
