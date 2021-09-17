#include <stdio.h>
#include "./include/philo_bonus.h"

t_mutex	mutex;

int main()
{
	pid_t	pid;
	int		i;

	pthread_mutex_init(&mutex, NULL);
	i = -1;
	pid = 1;
	while (pid != 0 && ++i < 3)
		pid = fork();
	if (pid == 0)
	{
		sleep(2);
		i = 0;
		pthread_mutex_lock(&mutex);
		while (i < 5)
		{
			printf("%u print mutex test\n", getpid());
			i++;
			usleep(1000);
		}
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		sleep(5);
	}
	return (0);
}
//결론 : mutex는 프로세스 간 상호배제를 해줄 수 없음.
