#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

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
	int				*prog;
	int				*fullcount;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*status_mutex;
	int				id;
	int				count;
	long			last;
	long			start;
	t_env			env;
}					t_philo;

void	print_msg(char *str, t_philo *p);
void	*monit_func(void *arg);
void	make_thread(t_philo *philo, t_env p);
void	end_thread(t_philo *philo, t_env p, pthread_mutex_t *m);

#endif
