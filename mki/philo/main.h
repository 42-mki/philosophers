/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:46 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 13:38:59 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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

# define TAKE	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

typedef struct		s_philo
{
	int				number;
	int				state;
	int				time_eat;
	int				last_eat;
}					t_philo;

typedef struct		s_var
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
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
long				get_time(void);
void				my_usleep(int wait_mili_time);
void				*pthread_routine(void *arg);
void				*pthread_print(void *arg);

#endif
