/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:49:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/04 23:49:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static int	find_new_line(char *buffer, int read_count)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && i < read_count)
		i++;
	if (i == read_count)
		return (-1);
	return (i);
}

static char *concat_strs(char *builder_str, char *buffer)
{
	char	*concatenated;

	concatenated = ft_strjoin(builder_str, buffer);
	free(builder_str);
	if (!concatenated)
		return (0);
	return (concatenated);
}

static char	*read_file(int fd, t_builder *builder)
{
	int		read_count;
	int		buffer_new_line_index;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	/*should print error of malloc function*/
	if (!buffer)
		return (0);
	while (builder->new_line_index == -1)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		/*should print error of read function*/
		if (read_count == -1)
			return (0);
		buffer_new_line_index = find_new_line(buffer, read_count);
		if (buffer_new_line_index == -1)
			builder->new_line_index += read_count;
		else
			builder->new_line_index += buffer_new_line_index;
		builder->str = concat_strs(builder->str, buffer);
		/*should print error of ft_strjoin's malloc function*/
		if (!(builder->str))
			return (0);
		builder->len += read_count;
	}
	return (builder->str);
}

static char	*make_line(t_builder *builder)
{
	char	*line;
	char	*temp_builder_str;

	temp_builder_str = builder->str;
	line = ft_substr(builder->str, 0, builder->new_line_index + 1);
	builder->str = ft_substr(builder->str, builder->new_line_index + 1, builder->len);
	/*should print error of ft_substr's malloc function*/
	if (!line || !(builder->str))
		return (0);
	free(temp_builder_str);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_builder	builder = {(char *)0, 0, -1};
	/*split if statment into multiple statment -> should print error of BUFFER_SIZE*/
	if (fd < 0 || BUFFER_SIZE < 1 || !read_file(fd, &buffer))
		return (0);
	return (make_line(&line, &builder));
}
