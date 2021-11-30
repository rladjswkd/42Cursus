#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
typedef struct s_builder
{
	char	*str;
	int		len;
	int		new_line_index;
}	t_builder;
char	*get_next_line(int fd);
#endif