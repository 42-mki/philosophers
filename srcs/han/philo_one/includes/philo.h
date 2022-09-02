/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:13:58 by han               #+#    #+#             */
/*   Updated: 2021/01/20 15:59:48 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define T_EAT		0
# define T_SLEEP	1
# define T_FORK		2
# define T_THINK	3
# define T_DIED		4
# define T_OVER		5

typedef struct		s_philo
{
	int				index;
	int				is_eat;
	uint64_t		last_eat;
	int				eat_count;
	uint64_t		limit;
	int				lfork;
	int				rfork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	must_eat;
}					t_philo;

typedef struct		s_info
{
	int				p_num;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	uint64_t		start_time;

	t_philo			*philos;
	pthread_mutex_t	*mt_forks;
	pthread_mutex_t	mt_write;
	pthread_mutex_t mt_dead;
}					t_info;

/*
**	utils.c
*/

t_info				*get_info(void);
unsigned long		get_time(void);
void				ft_putnbr(int n);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);

/*
**	utils2.c
*/

void				dp_msg(t_philo *philo, int type);

/*
**	exit.c
*/

int					exit_error(const char *msg);
int					free_info(t_info *info);

/*
**	philo.h
*/

int					start_threads(t_info *info);

/*
**	dinning.c
*/

void				eat(t_philo *philo);
void				take_forks(t_philo *philo);
void				down_forks(t_philo *philo);

#endif
