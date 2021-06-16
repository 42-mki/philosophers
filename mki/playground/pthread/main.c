#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*thread_routine(void *arg)
{
	pthread_t	tid;
	int			i;

	i = 0;
	tid = pthread_self();
	printf("\ttid:%x\n", (int)tid);
	while (i < 10)
	{
		printf("\tnew thread:%d\n", i);
		i++;
		sleep(1);
	}
	return (NULL);
}

int		main(void)
{
	pthread_t	thread;
	int			i;

	pthread_create(&thread, NULL, thread_routine, NULL);
	i = 0;
	printf("tid: %x\n", (int)pthread_self());
	while (i < 5)
	{
		printf("main:%d\n", i);
		i++;
		sleep(1);
	}
	pthread_join(thread, NULL);
	pthread_detach(thread);
	return (0);
}
