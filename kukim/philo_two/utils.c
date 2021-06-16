/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:59:37 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:59:38 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		error_msg(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (FAILURE);
}

int		check_arguments(int ac, char **av)
{
	int		i;

	if (!(ac == 5 || ac == 6))
		return (error_msg("Wrong arguments\n"));
	i = 1;
	while (i < ac)
		if (ft_strisdigit(av[i++]))
			return (error_msg("Wrong arguments\n"));
	if (ft_atoi(av[1]) > 1000 || ft_strlen(av[1]) > 4)
		return (error_msg("Max nb of philosophers : 1000\n"));
	if (ft_atoi(av[2]) > 1000000 || ft_strlen(av[2]) > 7
			|| ft_atoi(av[3]) > 1000000 || ft_strlen(av[3]) > 7
			|| ft_atoi(av[4]) > 1000000 || ft_strlen(av[4]) > 7)
		return (error_msg("Max time in ms for args 2/3/4 : 1000000ms\n"));
	if (av[5] && (ft_atoi(av[5]) > 1000000 || ft_strlen(av[5]) > 7))
		return (error_msg("Max nb of time philo can eat : 1000000\n"));
	if (!ft_atoi(av[2]) || !ft_atoi(av[3])
	|| !ft_atoi(av[4]) || (av[5] && !ft_atoi(av[5])))
		return (error_msg("Arguments must be positive and > 0\n"));
	return (SUCCESS);
}

int		print_ms_and_state(int id, int ms, char *str_msg)
{
	int		len_id;
	int		len_ms;
	char	tmp[100];

	len_id = -1;
	while (++len_id <= 99)
		tmp[len_id] = '\0';
	len_id = lennb_for_str(id);
	len_ms = lennb_for_str(ms);
	ft_putnbr_buffer(ms, tmp);
	ft_strlcpy(tmp + len_ms, "ms ", 4);
	ft_putnbr_buffer(id, tmp + len_ms + 3);
	ft_strlcpy(tmp + len_id + len_ms + 3, str_msg, ft_strlen(str_msg) + 1);
	ft_putstr_fd(tmp, 1);
	return (SUCCESS);
}

int		print_state_msg(t_philo *ph, int id_philo, suseconds_t ms, int type)
{
	sem_wait(ph->printing);
	if (!(*(ph->ph_die)) && type == EAT)
		print_ms_and_state(id_philo, ms, " is eating\n");
	else if (!(*(ph->ph_die)) && type == FORK)
		print_ms_and_state(id_philo, ms, " has taken a fork\n");
	else if (!(*(ph->ph_die)) && type == SLEEP)
		print_ms_and_state(id_philo, ms, " is sleeping\n");
	else if (!(*(ph->ph_die)) && type == THINK)
		print_ms_and_state(id_philo, ms, " is thinking\n");
	else if (!(*(ph->ph_die)) && type == DIE)
		print_ms_and_state(id_philo, ms, " has died\n");
	sem_post(ph->printing);
	return (SUCCESS);
}

long	get_time_ms(void)
{
	struct timeval	tmp_time;
	long			ms;

	gettimeofday(&tmp_time, NULL);
	ms = tmp_time.tv_sec * 1000;
	ms += tmp_time.tv_usec / 1000;
	return (ms);
}
