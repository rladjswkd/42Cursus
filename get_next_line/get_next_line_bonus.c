/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/11 19:44:06 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
static char	*read_file(t_builder *b)
{
	int		count;
	int		start;
	char	buffer[BUFFER_SIZE + 1];
	char	*new_line;

	start = 0;
	new_line = ft_strchr(b->data, '\n');
	while (!new_line)
	{
		count = read(b->fd, buffer, BUFFER_SIZE);
		if (count == -1 || (count == 0 && ft_strlen(b->data) == 0))
			return (0);
		if (count == 0)
			return (b->data + ft_strlen(b->data) - 1);
		buffer[count] = 0;
		b->data = concat_strs(b->data, buffer);
		if (!(b->data))
			return (0);
		new_line = ft_strchr(b->data + start, '\n');
		start += count;
	}
	return (new_line);
}

static char	*build_line(t_builder *b, char *new_line)
{
	char	*line;
	char	*temp_data;
	int		line_len;

	line_len = new_line - b->data + 1;
	line = ft_substr(b->data, 0, line_len);
	if (!line)
		return (0);
	temp_data = ft_substr(b->data, line_len, ft_strlen(b->data) - line_len + 1);
	if (!temp_data)
		return (0);
	free(b->data);
	b->data = temp_data;
	return (line);
}

static char	*free_builder_data(t_builder **b)
{
	t_builder	*temp;

	temp = (*b)->next;
	(*b)->next = ((*b)->next)->next;
	free(temp->data);
	free(temp);
	temp = 0;
	return (0);
}

static char	*get_next_line_fd(t_builder *b, int fd)
{
	char		*new_line;

	if (b->next == 0)
	{
		b->next = (t_builder *)malloc(sizeof(t_builder));
		if (!(b->next))
			return (0);
		(b->next)->fd = fd;
		(b->next)->data = (char *)malloc(sizeof(char));
		if ((b->next)->data == 0)
			return (0);
		(b->next)->next = 0;
		(b->next)->data[0] = '\0';
	}
	new_line = read_file(b->next);
	if (!new_line)
		return (0);
	return (build_line(b->next, new_line));
}

char	*get_next_line(int fd)
{
	static t_builder	before_head = {"", -1, 0};
	t_builder			*pointer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	pointer = &before_head;
	while (pointer && pointer->next && (pointer->next)->fd != fd)
		pointer = pointer->next;
	line = get_next_line_fd(pointer, fd);
	if (!line)
		return (free_builder_data(&pointer));
	return (line);
}
