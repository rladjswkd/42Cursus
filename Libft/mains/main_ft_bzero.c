#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
//	bzero((void *)0, 1); segfault occurs
	bzero((void *)0, 0);
	return (0);
}
