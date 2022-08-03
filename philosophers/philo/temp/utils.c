#include "philosophers.h"

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign = -1;
	if (48 > **str || **str > 57)
			return (0);
	return (sign);
}

int	get_int(char *str, int *val)
{
	int	sign;

	sign = get_sign(&str);
	if (sign < 1)
		return (0);
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '\0')
		return (0);
	return (1);
}
