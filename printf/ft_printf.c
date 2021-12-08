#include "ft_printf.h"
#include "../libft.h"
int	ft_printf(const char *format, ...)
{
	va_list	p;
	int		status;

	status = check_format(format);
	if (status < 0)
	va_start(p, 
}

static int	check_format(const char *format)
{
	int			count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_strchr(VALID_SET, *(format + 1)))
			{
				format++;
				count++;
			}
			else
				return (-1);
		}
		format++;
	}
	return (count);
}
/*
 * 1. format에 포함된 %의 개수 세기 -> 단, %%는 하나로 간주한다.
 * 2. va_start에 va_list pointer와 함께 구한 개수를 전달한다.
 * 3. format 문자열에서 % 뒤에 cspdiuxX% 중에 하나가 아닌 다른 것이 오면 에러. -> %%를 처리할 땐 두 번째 %에 대해서 동일한 처리를 하지 않게 주의하자.
 *
 * check_format은 format을 확인하고, 올바른 포맷이면 %의 개수, 그렇지 않으면 -1을 반환.
 * */
