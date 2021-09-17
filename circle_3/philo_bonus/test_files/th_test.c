#include "./include/philo_bonus.h"

void	*test(void *data)
{
	sleep(1);
	exit(0);
}

int main()
{
	t_pth th;

	pthread_create(&th, NULL, test, NULL);
	pthread_detach(th);
	sleep(2);
	printf("flag\n");
	return (0);
}
//thread에서 exit실행하면 프로세스도 종료됨.
