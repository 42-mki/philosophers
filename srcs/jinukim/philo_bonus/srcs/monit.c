#include "philo.h"

void	print_msg(char *str, t_philo *p)
{
	sem_wait(p->print_sem);
	if (p->status == P_ALIVE)
		printf("%6ld %3d %s", my_gettime(p->start), p->id, str);
	sem_post(p->print_sem);
}

void	*monit_func(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (p->status == P_ALIVE)
	{
		if (my_gettime(p->last) >= p->env.die)
		{
			sem_wait(p->print_sem);
			printf("%6ld %3d died\n", my_gettime(p->start), p->id);
			p->status = P_DIE;
			sem_post(p->die_sem);
		}
		if (p->env.end != -1 && p->count == p->env.end)
		{
			p->count++;
			sem_post(p->full_sem);
		}
	}
	return (0);
}

void	*isfull_func(void *arg)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)arg;
	i = -1;
	while (++i < p->env.n)
		sem_wait(p->full_sem);
	sem_wait(p->print_sem);
	printf("%6ld All philosophers are full\n", my_gettime(p->start));
	p->status = P_FULL;
	sem_post(p->die_sem);
	return (0);
}
