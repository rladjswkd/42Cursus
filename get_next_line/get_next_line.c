/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:49:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/07 19:48:06 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*free_builder_data(t_builder *builder)
{
	free(builder->data);
	builder->data = 0;
	return (0);
}

static int	read_file(int fd, t_builder *builder)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	char	*temp_data;

	while (builder->index == -1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 1)
			return (count);
		temp_data = concat_data(builder->data, buffer, builder->len, count);
		if (!temp_data)
			return (-1);
		builder->data = temp_data;
		builder->index = find_new_line(builder->data, builder->len, count);
		builder->len += count;
	}
	return (1);
}

static char	*build_line(t_builder *builder)
{
	char	*line;
	char	*temp_data;

	if (builder->index == -1)
	{
		if (builder->len == 0)
			return (0);
		line = (char *)malloc(sizeof(char) * (builder->len + 1));
		if (!line)
			return (0);
		copy_data(line, builder->data, builder->len + 1, 1);
		builder->len = 0;
		return (line);
	}
	line = get_part(builder->data, 0, builder->index + 1, 1);
	temp_data = get_part(builder->data,	
				builder->index + 1, builder->len - (builder->index + 1), 0);
	if (!line || !temp_data)
		return (0);
	free(builder->data);
	builder->data = temp_data;
	builder->len -= (builder->index + 1);
	builder->index = find_new_line(builder->data, 0, builder->len);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_builder	builder = {0, 0, -1};
	int					read_status;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	read_status = read_file(fd, &builder);
	if (read_status == -1)
		return (free_builder_data(&builder));
	line = build_line(&builder);
	if (line == 0)
		return (free_builder_data(&builder));
	return (line);
}
