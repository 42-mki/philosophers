# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/02/23 06:17:51 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR		=	ar -rcs
RM		=	rm -f
.SUFFIXES	=	.c.o

PART_I		=	ft_memset\
			ft_bzero\
			ft_memcpy\
			ft_memccpy\
			ft_memmove\
			ft_memchr\
			ft_memcmp\
			ft_strlen\
			ft_strlcpy\
			ft_strlcat\
			ft_strchr\
			ft_strrchr\
			ft_strnstr\
			ft_strncmp\
			ft_atoi\
			ft_isalpha\
			ft_isdigit\
			ft_isalnum\
			ft_isascii\
			ft_isprint\
			ft_toupper\
			ft_tolower\
			ft_calloc\
			ft_strdup\

PART_II		=	ft_substr\
			ft_strjoin\
			ft_strtrim\
			ft_split\
			ft_itoa\
			ft_strmapi\
			ft_putchar_fd\
			ft_putstr_fd\
			ft_putendl_fd\
			ft_putnbr_fd

PART_B		=	ft_lstnew\
			ft_lstadd_front\
			ft_lstsize\
			ft_lstlast\
			ft_lstadd_back\
			ft_lstdelone\
			ft_lstclear\
			ft_lstiter\
			ft_lstmap

MKI		=	ft_issep_bonus\
			ft_split_bonus

FILES		=	$(PART_I) $(PART_II) $(PART_B) $(MKI)
SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))) 
SRCS_B		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(PART_B))) 
OBJS_DIR	=	./
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES))) 
OBJS_B		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(PART_B))) 

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: clean all bonus fclean re
