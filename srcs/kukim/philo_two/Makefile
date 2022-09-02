# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 17:06:09 by kukim             #+#    #+#              #
#    Updated: 2021/01/19 17:13:35 by kukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_two
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c utils.c init.c libft.c libft2.c threads.c threads_main.c
OBJS		=	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(FLAGS) $(OBJS) -lpthread

%.o		:	%.c
			$(CC) $(FLAGS) -o $@ -c $<
# for creating .o with flags

clean	:	
				rm -rf $(OBJS)

fclean	:	clean
				rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
