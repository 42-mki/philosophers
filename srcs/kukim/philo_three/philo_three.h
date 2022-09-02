/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:36 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:15:51 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>

# define SUCCESS		0
# define FAILURE		1

# define EAT			0
# define FORK			1
# define THINK			2
# define SLEEP			3
# define DIE			4

# define S_FORKS		"sem_forks_p3"
# define S_TAKE			"sem_take_forks_p3"
# define S_PRINT		"sem_print_p3"
# define S_PHILO_DIE	"sem_philo_die_p3"
# define S_NB_PH_FED	"sem_nb_ph_fed_p3"

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
	sem_t			*nb_forks;
	long			time_start;
	long			time_last_meal;
	sem_t			*printing;
	sem_t			*take_forks;
	sem_t			*ph_die;
	sem_t			*nb_ph_fed;
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
int					create_t_philo_array(t_philo *ph, t_info *info);
pthread_mutex_t		*create_forks(int nb_forks);
void				launch_processes(t_philo *ph);

int					philo_life(t_philo *ph);
void				join_all_threads(t_philo *ph);
void				clean_exit(t_philo ph);

#endif
