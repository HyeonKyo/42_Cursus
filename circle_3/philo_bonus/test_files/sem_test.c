#include <stdio.h>
#include "./include/philo_bonus.h"

int main()
{
	sem_t *sem;
	pid_t pid;

	sem = sem_open("sem", O_CREAT, 644, 0);
	pid = fork();
	if (pid != 0)
	{
		sem_wait(sem);
		printf("sem is good!\n");
		sem_close(sem);
		sem_unlink("sem");
		return (0);
	}
	else
	{
		sleep(2);
		sem_post(sem);
	}
	sem_close(sem);
	sem_unlink("sem");
	return (0);
}
//결론 : sem값은 음수로 사용 불가
