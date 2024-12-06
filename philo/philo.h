/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:46 by mki               #+#    #+#             */
/*   Updated: 2021/06/12 12:24:59 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# include <stdio.h>

/*
** memset()					->	string.h
** malloc()					->	stdlib.h
** free()					->	stdlib.h
** write()					->	unistd.h
** usleep()					->	unistd.h
** gettimeofday()			->	sys/time.h
** pthread_create()			->	pthread.h
** pthread_detach()			->	pthread.h
** pthread_join()			->	pthread.h
** pthread_mutex_init()		->	pthread.h
** pthread_mutex_destroy()	->	pthread.h
** pthread_mutex_lock()		->	pthread.h
** pthread_mutex_unlock()	->	pthread.h
*/

# define TAKE	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

typedef struct		s_philo
{
	int				time_eat;
	int				last_eat;
	int				state;
	int				number;
}					t_philo;

typedef struct		s_var
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				end;
	unsigned int	base_time;
	unsigned int	cur_time;
	t_philo			*philos;
	pthread_t		*tids;
	pthread_t		tid_print;
	pthread_mutex_t	*mutexes;
}					t_var;

int					philo(t_var *var);
int					ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
unsigned long		init_time(void);
unsigned long		get_time(unsigned long time);

#endif
