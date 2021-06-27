# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 14:03:42 by mki               #+#    #+#              #
#    Updated: 2021/06/25 16:33:48 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread -fsanitize=address
AR			=	ar -rcs
RM			=	rm -f

FILES		=	action\
				ft_atoi\
				ft_itoa\
				ft_putstr_fd\
				main\
				print\
				pthread\
				time

DIR			=	./
SRCS		=	$(addprefix $(DIR), $(addsuffix .c, $(FILES))) 
OBJS		=	$(addprefix $(DIR), $(addsuffix .o, $(FILES))) 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$(NAME) 5 800 200 200
#	./$(NAME) 1 800 200 200
#	./$(NAME) 2 800 200 200
#	./$(NAME) 200 800 200 200
#	./$(NAME) 500 800 200 200
#	./$(NAME) 5 800 200 200 7
#	./$(NAME) 4 410 200 200
#	./$(NAME) 4 310 200 100
#	norminette *.c *.h
	make fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
