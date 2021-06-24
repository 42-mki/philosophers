# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 14:03:42 by mki               #+#    #+#              #
#    Updated: 2021/06/24 13:36:50 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread
AR			=	ar -rcs
RM			=	rm -f

FILES		=	ft_atoi\
				ft_itoa\
				ft_putstr_fd\
				main\
				mutex\
				philo\
				pthread\
				time

DIR			=	./
SRCS		=	$(addprefix $(DIR), $(addsuffix .c, $(FILES))) 
OBJS		=	$(addprefix $(DIR), $(addsuffix .o, $(FILES))) 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$(NAME) 5 800 200 200
#	./$(NAME) 5 800 200 200 7
#	./$(NAME) 4 410 200 200
#	./$(NAME) 4 310 200 100
	 norminette *.c *.h

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
