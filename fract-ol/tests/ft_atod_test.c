#include <stdio.h>
#include <stdlib.h>
#include <float.h>

double	ft_atod(char *str)
{
	long double	integer;
	double		scale;
       	int		sign;

	integer = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	while (47 < *str && *str < 58)
		integer = integer * 10 + sign * (*(str++) - 48);
	if (*str != '.' && *str != '\0')
	{
		printf("%s\n", "error\n");
		exit(EXIT_FAILURE);
	}
	if (*(str++) == '\0')
	       return (integer);
	scale = 10;
	while (47 < *str && *str < 58)
	{
		integer += sign *(*(str++) - 48) / scale;
		scale *= 10;
	}
	if (*str != '\0')
	{
		printf("%s\n", "error\n");
		exit(EXIT_FAILURE);
	}
	return ((double)integer);
}
int	main(void)
{
	printf("%lf\n" , DBL_MIN);
	printf("%lf\n", ft_atod("0.0"));
	printf("%lf\n", 123.456);
	printf("%lf\n", ft_atod("123.456"));
	printf("%lf\n" , DBL_MAX);
	printf("%lf\n", ft_atod("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"));
	printf("%lf\n", -123.456);
	printf("%lf\n", ft_atod("-123.456"));
}
