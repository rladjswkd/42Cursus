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
		builder->len += read_count;
	}
}

static void	make_line(t_builder *builder)
{
	int		i;
	
	i = -1;
	while (++i < builder->new_line_index)
		(*line)[i] = (builder->str)[i];
	(*line)[i] = 0;
}

char	*get_next_line(int fd)
{
	static t_builder	builder = {(char *)0, 0, -1};
	/*should print error of BUFFER_SIZE*/
	if (BUFFER_SIZE < 1 || !read_file(fd, &buffer))
		return (0);
	return (make_line(&line, &builder));
}
