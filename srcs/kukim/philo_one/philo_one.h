/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:59:30 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:59:31 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS	0
# define FAILURE	1

# define EAT		0
# define FORK		1
# define THINK		2
# define SLEEP		3
# define DIE		4

typedef struct		s_pdata
{
	pthread_mutex_t	mutex;
	int				data;
}					t_pdata;

typedef struct		s_info
{
	int				nb_ph;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				nb_each_ph_eat;
}					t_info;

typedef struct		s_philo
{
	int				id;
	t_info			*info;
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	long			time_start;
	long			time_last_meal;
	t_pdata			*ph_die;
	int				*nb_ph_fed;
}					t_philo;

int					error_msg(char *str);
int					check_arguments(int ac, char **av);
int					print_ms_and_state(int id, int ms, char *str_msg);
int					print_state_msg(t_philo *ph, int id_philo,
suseconds_t ms, int type);
long				get_time_ms(void);

size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
int					ft_strisdigit(char *str);
long				ft_atoi(const char *str);
char				*ft_itoa(long n);
void				better_sleep(long d);
int					lennb(unsigned int nb);
int					lennb_for_str(unsigned int nb);
void				ft_putnbr_buffer(int n, char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

void				init_t_info(t_info *info, int ac, char **av);
t_philo				*create_t_philo_array(pthread_mutex_t *mutex,
int *nb_ph_fed, t_pdata *ph_die, t_info *info);
pthread_mutex_t		*create_forks(int nb_forks);
void				launch_threads(t_philo *ph);

void				*philo_life(void *ph);
void				philo_eat(t_philo *ph, int *nb_of_time_ph_ate);
void				*check_philo_alive(void *tmp);
void				join_all_threads(t_philo *ph);
void				clean_exit(t_philo *ph);

#endif
