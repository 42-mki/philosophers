/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:46 by mki               #+#    #+#             */
/*   Updated: 2021/06/25 16:31:26 by mki              ###   ########.fr       */
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

typedef struct		s_global
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				*fork;
	long			base_time;
	long			cur_time;
	int				monitor_flag;
	pthread_t		*thread_id;
	pthread_t		tid_print;
	pthread_mutex_t	*mutex_id;
	pthread_mutex_t	mutex_print;
}					t_global;

typedef struct		s_philo
{
	int				number;
	int				left_fork;
	int				right_fork;
	int				old_state;
	int				state;
	long			last_eat;
	int				eat_cnt;
	t_global		*global;
}					t_philo;

int					philo(t_global *global);
int					ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
unsigned long		init_time(void);
long				get_time(void);
void				my_usleep(int wait_mili_time);
void				*pthread_routine(void *arg);
void				*pthread_monitor(void *arg);
void				taken_fork(t_philo *philo, int fork_num, int philo_num);
void				return_fork(t_philo *philo, int right_fork, int left_fork);
void				print_state(pthread_mutex_t *mutex, int time, int number, int state);

#endif
