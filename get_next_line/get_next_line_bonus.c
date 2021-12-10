/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/10 14:39:12 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
static char	*read_file(t_builder *b)
{
	int		count;
	char	buffer[BUFFER_SIZE + 1];
	char	*new_line;
	char	*temp_data;

	if (b->data)
		new_line = ft_strchr(b->data, '\n');
	else
		new_line = 0;
	while (!new_line)
	{
		count = read(b->fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (0);
		if (count == 0)
			return (b->data + ft_strlen(b->data) - 1);
		buffer[count] = 0;
		temp_data = concat_strs(b->data, buffer);
		if (!temp_data)
			return (0);
		b->data = temp_data;
		new_line = ft_strchr(b->data, '\n');
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

static char	*free_builder_data(t_builder *b)
{
	t_builder	*next;
	t_builder	*current;

	current = b->next;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	b->next = 0;
	return (0);
}

static char	*get_next_line_fd(t_builder *b, int fd)
{
	char		*new_line;
	t_builder	*origin;

	origin = b;
	if (b->fd != fd)
	{
		b->next = (t_builder *)malloc(sizeof(t_builder));
		if (!(b->next))
			return (0);
		(b->next)->fd = fd;
		(b->next)->data = (char *)malloc(sizeof(char));
		if ((b->next)->data == 0)
			return (0);
		(b->next)->data[0] = '\0';
		b = b->next;
	}
	new_line = read_file(b);
	if (!new_line)
		return (0);
	if (new_line < b->data)
		return (origin->data);
	return (build_line(b, new_line));
}

char	*get_next_line(int fd)
{
	static t_builder	b = {"", -1, 0};
	t_builder			*pointer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	pointer = &b;
	while (pointer && pointer->fd != fd && pointer->next)
		pointer = pointer->next;
	line = get_next_line_fd(pointer, fd);
	if (!line)
		return (free_builder_data(&b));
	if (line == pointer->data)
		return (0);
	return (line);
}
