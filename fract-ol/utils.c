#include "fractal.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

static int	get_sign(char **str)
{
       	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign = -1;
	return (sign);
}

double	*get_double(char *str, double *val)
{
	long double	temp;
	double		scale;
       	int		sign;

	sign = get_sign(&str);
	temp = 0;
	while (47 < *str && *str < 58)
		temp = temp * 10 + sign * (*(str++) - 48);
	if (*str != '.' && *str != '\0')
		return (0);
	*val = (double)temp;
	if (*str == '\0')
		return (val);
	str++;
	scale = 10;
	while (47 < *str && *str < 58)
	{
		temp += sign * (*(str++) - 48) / scale;
		scale *= 10;
	}
	if (*str != '\0')
		return (0);
	*val = (double)temp;
	return (val);
}

int	*get_int(char *str, int *val)
{
	int	sign;

	sign = get_sign(&str);
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '\0')
		return (0);
	return (val);
}
