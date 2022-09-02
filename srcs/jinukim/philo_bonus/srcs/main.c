#include "philo.h"

t_env	init_param(int argc, char **argv)
{
	t_env	ret;
	int		i;

	if (argc < 5 || argc > 6)
		err_msg("invalid num of args.\n");
	memset(&ret, 0, sizeof(t_env));
	i = 0;
	while (++i < argc)
		if (!ft_isdigit(argv[i]))
			err_msg("Non numeric character exists on arg\n");
	ret.n = ft_atoi(argv[1]);
	ret.die = ft_atoi(argv[2]);
	ret.eat = ft_atoi(argv[3]);
	ret.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ret.end = ft_atoi(argv[5]);
	else
		ret.end = -1;
	if (ret.end == 0)
		err_msg("number of meals to eat cannot 0\n");
	return (ret);
}

t_philo	*init_philo(t_env p)
{
	t_philo			*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		err_msg("malloc error!\n");
	memset(philo, 0, sizeof(t_philo));
	sem_unlink("fork_sem");
	sem_unlink("die_sem");
	sem_unlink("full_sem");
	sem_unlink("print_sem");
	philo->fork_sem = sem_open("fork_sem", O_CREAT, 0644, p.n / 2);
	philo->die_sem = sem_open("die_sem", O_CREAT, 0644, 0);
	philo->full_sem = sem_open("full_sem", O_CREAT, 0644, 0);
	philo->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	philo->start = my_gettime(0L);
	philo->last = philo->start;
	philo->env = p;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_env		p;
	t_philo		*philo;
	pid_t		*pid;

	p = init_param(argc, argv);
	philo = init_philo(p);
	pid = make_process(philo, p);
	end_process(philo, p, pid);
}
