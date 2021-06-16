/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:13:58 by han               #+#    #+#             */
/*   Updated: 2021/01/20 16:00:18 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define SEM_FORK		"pSemaphoreFork"
# define SEM_WRITE		"pSemaphoreWrite"
# define SEM_DEAD		"pSemaphoreDead"
# define SEM_PHILO		"pSemaphorePhilo"
# define SEM_PHILOEAT	"pSemaphorePhiloEat"

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
	sem_t			*mutex;
	sem_t			*must_eat;
}					t_philo;

typedef struct		s_info
{
	int				p_num;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	int				cur_eat_count;
	uint64_t		start_time;
	int				over;

	t_philo			*philos;
	sem_t			*sem_forks;
	sem_t			*sem_write;
	sem_t			*sem_dead;
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

int					dp_msg(t_philo *philo, int type);
int					ft_strlcpy(char *dst, const char *src);

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

int					eat(t_philo *philo);
int					take_forks(t_philo *philo);
int					down_forks(t_philo *philo);

/*
**	semaphores.c
*/

sem_t				*ft_sem_open(char const *name, int value);
char				*make_semaphore_name(char const *base,
									char *buffer, int position);

#endif
