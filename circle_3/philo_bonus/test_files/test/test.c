#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t	mt;
int num = 0;

void	*iter_func(void *data)
{
	char *s;

	s = (char *)data;
	usleep(100);
	pthread_mutex_lock(&mt);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10000; j++)
			num += 1;
		printf("%d | [%s], %d\n", i + 1, s, num);
	}
	pthread_mutex_unlock(&mt);
	return (0);
}

void	*test_func(void *data)
{
	int	i = 0;
	char *s;

	s = (char *)data;
	i = 0;
	pthread_mutex_lock(&mt);
	while (i < 100000)
	{
		if (i % 10000 == 0)
			printf("{%s}, wait!\n", s);
		i++;
	}
	pthread_mutex_unlock(&mt);
	return (0);
}

int main()
{
	char *s1 = "Thread1";
	char *s2 = "Thread2";
	int	status;
	pthread_t	pth[2];

	pthread_mutex_init(&mt, NULL);
	sleep(1);
	pthread_create(&pth[0], NULL, test_func, (void *)s1);
	pthread_create(&pth[1], NULL, iter_func, (void *)s2);
	pthread_join(pth[0], (void **)&status); //6
	pthread_join(pth[1], (void **)&status);
	printf("end\n");
	return (0);
}
