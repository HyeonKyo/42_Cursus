#include "./include/philo_bonus.h"

int main()
{
	pid_t	pid;
	pid_t	gpid;

	pid = fork();
	if (pid != 0)
	{
		gpid = getpgrp();
		printf("main %u\n", gpid);
		pid = fork();
		if (pid == 0)
		{
			gpid = getpgrp();
			sleep(1);
			printf("fork2 %u\n", gpid);
			return (0);
		}
	}
	else
	{
		gpid = getpgrp();
		sleep(1);
		printf("fork1 %u\n", gpid);
		return (0);
	}
	sleep(5);
	waitpid(0, NULL, 0);
	//waitpid(0, NULL, 0);
	printf("main term\n");
	return (0);
}
//1. 그룹 프로세스 아이디 gid는 부모와 자식이 같은 값을 가짐
//2. waitpid는 하나의 자식 프로세스 종료만 기다림.
//	 여러 자식 프로세스가 모두 종료되기를 기다리지 않음.
//3. waitpid는 종료할 프로세스가 없으면 알아서 종료됨.
