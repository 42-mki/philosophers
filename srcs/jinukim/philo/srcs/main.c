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

pthread_mutex_t	*init_mutex(t_env p)
{
	int				i;
	pthread_mutex_t	*m;

	m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p.n);
	if (!m)
		err_msg("malloc error!\n");
	i = -1;
	while (++i < p.n)
		pthread_mutex_init(&m[i], 0);
	return (m);
}

t_philo	*init_philo(t_env p, pthread_mutex_t *m)
{
	t_philo			*philo;
	int				i;

	philo = (t_philo *)malloc(sizeof(t_philo) * p.n);
	memset(philo, 0, sizeof(t_philo) * p.n);
	if (!philo)
		err_msg("malloc error!\n");
	philo[0].prog = (int *)malloc(sizeof(int));
	philo[0].fullcount = (int *)malloc(sizeof(int));
	philo[0].status_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[0].status_mutex, 0);
	i = -1;
	while (++i < p.n)
	{
		philo[i].prog = philo[0].prog;
		philo[i].fullcount = philo[0].fullcount;
		philo[i].start = my_gettime(0L);
		philo[i].id = i + 1;
		philo[i].left_fork = &m[i];
		philo[i].right_fork = &m[(i + 1) % p.n];
		philo[i].status_mutex = philo[0].status_mutex;
		philo[i].env = p;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_env			p;
	pthread_mutex_t	*m_fork;
	t_philo			*philo;

	p = init_param(argc, argv);
	m_fork = init_mutex(p);
	philo = init_philo(p, m_fork);
	make_thread(philo, p);
	end_thread(philo, p, m_fork);
}
