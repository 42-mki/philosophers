#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

long	my_gettime(long bef);
void	my_usleep(long time);
void	err_msg(char *str);
int		ft_isdigit(char *str);
int		ft_atoi(char *str);

#endif
