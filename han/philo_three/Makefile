# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: han <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:57:07 by han               #+#    #+#              #
#    Updated: 2021/01/19 21:14:37 by han              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three
FLAG = -Wall -Wextra -Werror
INC = -I./includes
LIB = -lpthread
SRC = main.c philo.c utils.c utils2.c exit.c dinning.c semaphores.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAG) $(OBJ) $(INC) $(LIB) -o $(NAME)

$(OBJ): $(SRC)
	gcc $(FLAG) $(INC) -c $(SRC)

clean:
	rm -rf $(OBJ) result

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
