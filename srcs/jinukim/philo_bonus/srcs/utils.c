#include "utils.h"

long	my_gettime(long bef)
{
	struct timeval	t;
	long			now;

	t.tv_sec = 0;
	t.tv_usec = 0;
	gettimeofday(&t, 0);
	now = t.tv_sec * 1000L + t.tv_usec / 1000L;
	return (now - bef);
}

void	my_usleep(long time)
{
	long			end;

	end = my_gettime(0L) * 1000 + time;
	while (my_gettime(0L) * 1000 < end)
		usleep(100);
}

void	err_msg(char *str)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
			;
		write(2, str, i);
	}
	exit(-1);
}

int	ft_isdigit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long long int	ret;
	int				i;

	i = -1;
	while (str && str[++i])
		;
	if (i <= 0)
		err_msg("nothing in arg\n");
	if (i > 12)
		err_msg("not in 'int' range.\n");
	i = -1;
	ret = 0;
	while (str[++i])
		ret = ret * 10 + str[i] - '0';
	if (ret < -2147483648LL || ret > 2147483647LL)
		err_msg("not in 'int' range.\n");
	return (ret);
}
