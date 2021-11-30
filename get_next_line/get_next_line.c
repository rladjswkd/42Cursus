#include "get_next_line.h"
static int	find_new_line(char *buffer, int read_cnt)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && i < read_cnt)
		i++;
	if (i == read_cnt)
		return (-1);
	return (i);
}

static void read_file(int fd, char *buffer, t_builder **remain)
{
	int	read_cnt;
	int	new_line_index;

	new_line_index = -1;
	while (new_line_index == -1)
	{
		read_cnt = read(fd, buffer, BUFFER_SIZE);
		if (read_cnt == -1)
			
		new_line_index = find_new_line(buffer, read_cnt);
		(*remain)->str = concat_strs((*remain)->str, buffer);
		(*remain)->len += read_cnt;
		(*remain)->new_line_index += read_cnt;
	}
	(*remain)->new_line_index += new_line_index + 1 - read_cnt;
}

static void	make_line(char **line, t_builder *remain)
{
	int		i;
	
	i = -1;
	while (++i < (*remain)->new_line_index)
		(*line)[i] = (remain->str)[i];
	(*line)[i] = 0;
}

char	*get_next_line(int fd)
{
	char				*buffer;
	static t_builder	*remain;
	char				*line;

	(*remain)->len = 0;
	(*remain)->new_line_index = -1;
	if (BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == 0)
		return (0);
	read_file(fd, buffer, &remain);
	if (!(remain->str))
		return (0);
	line = (char *)malloc(sizeof(char) * (*remain)->new_line_index + 1);
	if (line == 0)
		return (0);
	make_line(&line, remain);
	return (line);
}
