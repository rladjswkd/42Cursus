#include "test.h"

// 당연히 프로세스마다 가상 메모리가 별도로 생성되기 때문에
// 자식 프로세스와 부모 프로세스 간에 변수가 동기화되지 않는 게 당연하다.
int	main(void)
{
	pid_t	cp;
	int	*val;

	val = (int *)malloc(sizeof(int));
	*val = 5;
	cp = fork();
	if (cp == 0)
	{
		*val += 5;
		exit(0);
	}
	else
	{
		sleep(1);
		printf("%d\n", *val) // 5가 출력됨.
	}
	return (0);
}
