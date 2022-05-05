#include "philosophers.h"

/*
 * thread-safe하게 문자열을 출력하려면 timestamp, thread id, 뒤에 나오는 문자열을 묶어서 하나의 문자열로 만들고 write를 호출해야 한다.
 */
static void	put_string(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	helper(int n, int sign)
{
	char	val;

	if (n < -9 || n > 9)
		helper(n / 10, sign);
	val = (n % 10) * sign + 48;
	write(1, &val, 1);
}

static void	put_number(int n)
{
	char	sign;

	sign = '-';
	if (n < 0)
		write(1, &sign, 1);
	helper(n, 1 + (-2 * (n < 0)));
}

void	print_state(int time, int id, char *str)
{
	put_number(time);
	write(1, " ", 1);
	put_number(id);
	write(1, " ", 1);
	put_string(str);
	write(1, "\n", 1);
}
