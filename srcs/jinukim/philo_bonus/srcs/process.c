#include "philo.h"

void	eating(t_philo *p)
{
	sem_wait(p->fork_sem);
	print_msg("has taken a fork\n", p);
	print_msg("has taken a fork\n", p);
	print_msg("is eating\n", p);
	p->last = my_gettime(0L);
	my_usleep(p->env.eat * 1000);
	p->count++;
	sem_post(p->fork_sem);
}

void	process_func(t_philo *p)
{
	pthread_t	monit;

	pthread_create(&monit, 0, monit_func, (void *)p);
	pthread_detach(monit);
	if (p->id % 2 == 0)
		my_usleep(p->env.eat * 500);
	while (p->status == P_ALIVE)
	{
		eating(p);
		if (p->env.end == -1 || p->count < p->env.end)
			print_msg("is sleeping\n", p);
		my_usleep(p->env.sleep * 1000);
		print_msg("is thinking\n", p);
		usleep(50);
	}
}

pid_t	*make_process(t_philo *philo, t_env p)
{
	int			i;
	pid_t		*pid;
	pthread_t	fullcheck;

	if (philo->env.end != -1)
	{
		pthread_create(&fullcheck, 0, isfull_func, (void *)philo);
		pthread_detach(fullcheck);
	}
	i = -1;
	pid = (pid_t *)malloc(sizeof(pid_t) * p.n);
	while (++i < p.n)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			err_msg("fork error\n");
		if (pid[i] == 0)
		{
			philo->id = i + 1;
			process_func(philo);
			exit(0);
		}
	}
	return (pid);
}

void	end_process(t_philo *philo, t_env p, pid_t *pid)
{
	int		i;

	sem_wait(philo->die_sem);
	i = -1;
	while (++i < p.n)
		kill(pid[i], SIGTERM);
	sem_unlink("fork_sem");
	sem_unlink("die_sem");
	sem_unlink("full_sem");
	sem_unlink("print_sem");
	sem_close(philo->fork_sem);
	sem_close(philo->die_sem);
	sem_close(philo->full_sem);
	sem_close(philo->print_sem);
	free(philo);
	free(pid);
}
