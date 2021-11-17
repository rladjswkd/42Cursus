#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
int	main(void)
{
	char	arr[100] = "-123asdf456";
	char	arr1[100] = "--123asdf456";
	char	arr2[100] = "-+123asdf456";
	char	arr3[100] = "   -123asdf456";
	char	arr4[100] = "   -2147483648";
	char	arr5[100] = "asdf123asdf456";
	char	arr6[100] = "-asdf123asdf456";
	char	arr7[100] = "+123asdf";
	char	arr8[100] = "++123asdf";
	char	arr9[100] = "+-123asdf";
	char	arr10[100] = "2147483647";
	printf("%d %s\n", atoi(arr), arr);
	printf("%d %s\n", ft_atoi(arr), arr);
	printf("%d %s\n", atoi(arr1), arr1);
	printf("%d %s\n", ft_atoi(arr1), arr1);
	printf("%d %s\n", atoi(arr2), arr2);
	printf("%d %s\n", ft_atoi(arr2), arr2);
	printf("%d %s\n", atoi(arr3), arr3);
	printf("%d %s\n", ft_atoi(arr3), arr3);
	printf("%d %s\n", atoi(arr4), arr4);
	printf("%d %s\n", ft_atoi(arr4), arr4);
	printf("%d %s\n", atoi(arr5), arr5);
	printf("%d %s\n", ft_atoi(arr5), arr5);
	printf("%d %s\n", atoi(arr6), arr6);
	printf("%d %s\n", ft_atoi(arr6), arr6);
	printf("%d %s\n", atoi(arr7), arr7);
	printf("%d %s\n", ft_atoi(arr7), arr7);
	printf("%d %s\n", atoi(arr8), arr8);
	printf("%d %s\n", ft_atoi(arr8), arr8);
	printf("%d %s\n", atoi(arr9), arr9);
	printf("%d %s\n", ft_atoi(arr9), arr9);
	printf("%d %s\n", atoi(arr10), arr10);
	printf("%d %s\n", ft_atoi(arr10), arr10);
	return (0);
}
