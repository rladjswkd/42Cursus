#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd = open("minimalist.rt", O_RDONLY);
	char	*p;
	while ((p = get_next_line(fd)) > 0)
		printf("%s\n", p);
	return (0);
}