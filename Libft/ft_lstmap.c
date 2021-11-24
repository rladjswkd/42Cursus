/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:10:44 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/25 00:10:44 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*next;

	if (!lst || !f || !del)
		return ((t_list *)0);
	header = (t_list *)0;
	while (lst)
	{
		next = ft_lstnew((*f)(lst->content));
		if (!next)
		{
			ft_lstclear(&header, del);
			return ((t_list *)0);
		}
		ft_lstadd_back(&header, next);
		lst = lst->next;
	}
	return (header);
}
