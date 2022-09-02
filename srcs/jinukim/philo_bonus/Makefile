NAME 		= philo_bonus

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

INCLUDE 	= ./includes/
SRCS_DIR 	= ./srcs

SRCS		= $(addprefix $(SRCS_DIR)/,\
			  main.c\
			  process.c\
			  monit.c\
			  utils.c)
OBJS 		= $(SRCS:.c=.o)
DEPS 		= $(SRCS:.c=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lpthread

clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -MD -c -o $@ $< -I$(INCLUDE)

-include $(DEPS)

.PHONY: all clean fclean re bonus
