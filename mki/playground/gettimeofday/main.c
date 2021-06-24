#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

/*
**	#include <sys/time.h>
**	int
**	gettimeofday(struct timeval *restrict tp, void *restrict tzp);
**
**	struct timeval {
**		time_t       tv_sec;   seconds since Jan. 1, 1970
**		suseconds_t  tv_usec;  and microseconds
**	};
*/

long	get_time(struct timeval tp)
{
	// printf("tv_sec: %ld tv_usec: %u\n", tp.tv_sec, tp.tv_usec);
	// printf("milisecond: %lu\n", tp.tv_sec * 1000 + tp.tv_usec / 1000);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	sleep_divide(int time)
{
	while (time)
	{
		time /= 2;
		usleep(time);
	}
}

int		main(void)
{
	long			start;
	struct timeval	tp_start;
	struct timeval	tp_cur;

	// start = get_time();
	gettimeofday(&tp_start, NULL);
	while (1)
	{
		gettimeofday(&tp_cur, NULL);
		printf("mili %lu\n", get_time(tp_cur) - get_time(tp_start));
		sleep_divide(1000);
	}
	return (0);
}
