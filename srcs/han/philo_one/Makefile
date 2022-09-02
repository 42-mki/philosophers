# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: han <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:57:09 by han               #+#    #+#              #
#    Updated: 2021/01/19 18:46:02 by han              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
FLAG = -Wall -Wextra -Werror
INC = -I./includes
LIB = -lpthread
SRC = utils.c utils2.c main.c philo.c dinning.c exit.c

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
