#include "test.h"

int	main(void)
{
	pid_t	cp;
	pid_t	cp2;
	sem_t	*sem;
	int	sval;

	sem_unlink("/sem");
	/*
	// 한 번 이 프로그램을 생성해서 /sem이라는 이름의 semaphore가 생성되면, 이 프로세스가 종료된다고 /sem이 제거되는 게 아니다.
	// 이 명령을 주석처리하면 sem_open이 널 포인터를 반환한다.
	sem = sem_open("/sem", O_CREAT | O_EXCL, 0644, 1);
	sem_getvalue(sem, &sval);
	printf("before fork(): %d\n", sval);
	cp = fork();
	if (cp == 0)
	{
		sem_getvalue(sem, &sval);
		printf("before child sem_wait(): %d\n", sval);
		sem_wait(sem);
		sem_getvalue(sem, &sval);
		printf("after child sem_wait(): %d\n", sval);
		exit(0);
	}
	else
	{
		//sleep(1) // 자식 프로세스보다 먼저 부모 프로세스가 sem_wait을 걸고 종료하면 자식 프로세스는 실행하지 못하고 그냥 종료된다.
		sem_getvalue(sem, &sval);
		printf("before parent sem_wait(): %d\n", sval);
		sem_wait(sem);
		sem_getvalue(sem, &sval);
		printf("after parent sem_wait(): %d\n", sval);
	}
	*/
	// 하나의 스레드/ 프로세스에서 semaphore의 모든 포크를 다 잡을 수 있다.
	sem_unlink("/sem");
	sem = sem_open("/sem", O_CREAT | O_EXCL, 0644, 2);

	sem_getvalue(sem, &sval);
	printf("before first sem_wait(): %d\n", sval);
	sem_wait(sem);

	sem_getvalue(sem, &sval);
	printf("before second sem_wait(): %d\n", sval);
	sem_wait(sem);

	sem_getvalue(sem, &sval);
	printf("after all sem_wait(): %d\n", sval);

	return (0);
}
