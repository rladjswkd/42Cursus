/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:49:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/05 22:54:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*read_file(int fd, t_builder *builder)
{
	int		count;
	char	buffer[BUFFER_SIZE];

	while (builder->index == -1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 1)
			return (0);
		builder->data = concat_data(builder->data, buffer, builder->len, count);
		if (!(builder->data))
			return (0);
		builder->index = find_new_line(builder->data, builder->len, count);
		builder->len += count;
	}
	return (builder->data);
}

static char	*build_line(t_builder *builder)
{
	char	*line;
	char	*temp_data;

	if (builder->index == -1)
	{
		line = (char *)malloc(sizeof(char) * (builder->len + 1));
		copy_data(line, builder->data, builder->len + 1, 1);
		free(builder->data);
		builder->data = 0;
		return (line);
	}
	temp_data = builder->data;
	line = get_part(builder->data, 0, builder->index + 1, 1);
	builder->data = get_part(builder->data,
			builder->index + 1, builder->len - (builder->index + 1), 0);
	if (!line || !(builder->data))
		return (0);
	builder->len -= (builder->index + 1);
	builder->index = find_new_line(builder->data, 0, builder->len);
	if (builder->len == 0)
		free(builder->data);
	free(temp_data);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_builder	builder = {0, 0, -1};

	if (fd < 0 || BUFFER_SIZE < 1
		|| (!read_file(fd, &builder) && !(builder.data)))
		return (0);
	return (build_line(&builder));
}
