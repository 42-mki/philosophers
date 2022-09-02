#include "philo.h"

void	eating(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	print_msg("has taken a fork\n", p);
	pthread_mutex_lock(p->right_fork);
	print_msg("has taken a fork\n", p);
	print_msg("is eating\n", p);
	p->last = my_gettime(0L);
	my_usleep(p->env.eat * 1000);
	p->count++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	*thread_func(void *arg)
{
	t_philo		*p;
	pthread_t	monit;

	p = (t_philo *)arg;
	p->last = my_gettime(0L);
	pthread_create(&monit, 0, monit_func, arg);
	if (p->id % 2 == 0)
		my_usleep(p->env.eat * 500);
	while (*p->prog == P_ALIVE)
	{
		eating(p);
		if (p->env.end == -1 || p->count < p->env.end)
			print_msg("is sleeping\n", p);
		my_usleep(p->env.sleep * 1000);
		print_msg("is thinking\n", p);
	}
	pthread_join(monit, 0);
	return (0);
}

void	make_thread(t_philo *philo, t_env p)
{
	int		i;

	*philo->prog = 0;
	*philo->fullcount = 0;
	i = -1;
	while (++i < p.n)
		if (pthread_create(&philo[i].thread, 0, thread_func, &philo[i]) < 0)
			err_msg("pthread create error\n");
}

void	end_thread(t_philo *philo, t_env p, pthread_mutex_t *m)
{
	int		i;

	i = -1;
	while (++i < p.n)
		pthread_join(philo[i].thread, 0);
	while (--i >= 0)
		pthread_mutex_destroy(&m[i]);
	pthread_mutex_destroy(philo->status_mutex);
	free(philo->status_mutex);
	free(philo->prog);
	free(philo->fullcount);
	free(m);
	free(philo);
}
