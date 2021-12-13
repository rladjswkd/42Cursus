#include <stdio.h>
int	main(void)
{
	char	*charr = "abcd";
	printf("%d\n", *charr & 2147483647);//output is 97 because *charr is 'a'.
	return (0);
}
