/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:49:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/09 22:46:11 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*free_builder_data(t_builder *builder)
{
	free(builder->data);
	builder->data = 0;
	return (0);
}

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

char	*get_next_line(int fd)
{
	static t_builder	builder = {0, 0, 0};
	char				*new_line;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	builder.fd = fd;
	if (builder.data == 0)
	{
		builder.data = (char *)malloc(sizeof(char) * 1);
		builder.data[0] = 0;
	}
	new_line = read_file(&builder);
	if (!new_line || new_line < builder.data)
		return (free_builder_data(&builder));
	line = build_line(&builder, new_line);
	if (line == 0)
		return (free_builder_data(&builder));
	return (line);
}
