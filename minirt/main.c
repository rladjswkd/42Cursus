#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int		fd;
	char	*p;

	fd = open("minimalist.rt", O_RDONLY);
	if (fd < 0)
		return (0); // 에러 문자열 출력하고 처리해주기
	while (1) // 개행문자만 나오면 넘기기
	{
		p = get_next_line(fd);
		if (p[0] == '\n')
			continue ;
	}
	return (0);
}