#include "./include/philo_bonus.h"

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		sleep(10);
		return (0);
	}
	else
	{
		sleep(2);
		kill(pid, SIGTERM);
		printf("term\n");
		sleep(1);
		kill(pid, SIGTERM);
	}
	printf("finished\n");
	return (0);
}
//시그널을 종료된 프로세스에 보내도 상관없음.
