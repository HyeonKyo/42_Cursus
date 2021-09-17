#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	g_data = 0;
pthread_mutex_t mutex;

void *p_function(void * data)
{
  pid_t pid; //process id
  pthread_t tid; // thread id
  char* thread_name;
  int	i;

  pid = getpid(); //4
  tid = pthread_self();

  thread_name = (char *)data;
  i = 0;
	pthread_mutex_lock(&mutex);
  while(i<3)
  {
    printf("%s, tid : %x, pid : %u, gdata : %d\n", thread_name, (unsigned int)tid, (unsigned int)pid, g_data++); //5
    i++;
    sleep(1);
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}


int main(void)
{
  pthread_t pthread[2];
  int thr_id;
  int status;
  char p1[] = "thread_1";
  char p2[] = "thread_2";
  char p3[] = "thread_3";

  pthread_mutex_init(&mutex, NULL);
  sleep(1); //1

  thr_id = pthread_create(&pthread[0], NULL, p_function, (void*)p1); //2
  if(thr_id < 0)
  {
    perror("pthread0 create error");
    exit(EXIT_FAILURE);
  }

  thr_id = pthread_create(&pthread[1], NULL, p_function, (void *)p2); //2
  if(thr_id < 0)
  {
    perror("pthread1 create error");
    exit(EXIT_FAILURE);
  }

  p_function((void *)p3); //3

  pthread_join(pthread[0], (void **)&status); //6
  pthread_join(pthread[1], (void **)&status);

  printf("end??\n");
  return 0;
}
