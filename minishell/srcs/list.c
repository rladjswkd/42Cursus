/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:53:26 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/08 19:53:28 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

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
