#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# include "utils.h"

# define P_ALIVE 0
# define P_DIE 1
# define P_FULL 2

typedef struct s_env
{
	int		n;
	int		die;
	int		eat;
	int		sleep;
	int		end;
}			t_env;

typedef struct s_philo
{
	sem_t		*fork_sem;
	sem_t		*die_sem;
	sem_t		*full_sem;
	sem_t		*print_sem;
	int			status;
	int			count;
	int			id;
	long		last;
	long		start;
	t_env		env;
}				t_philo;

void	print_msg(char *str, t_philo *p);
void	*monit_func(void *arg);
void	*isfull_func(void *arg);
pid_t	*make_process(t_philo *philo, t_env p);
void	end_process(t_philo *philo, t_env p, pid_t *pid);

#endif
