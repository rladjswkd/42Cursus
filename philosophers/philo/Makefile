# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 23:19:26 by gyepark           #+#    #+#              #
#    Updated: 2022/08/10 23:22:46 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIB		= -pthread
RM		= rm -f

SRCS 	= arguments.c\
		  construct.c\
		  core.c\
		  cycle.c\
		  destruct.c\
		  handle.c\
		  main.c\
		  monitor.c\
		  mutexes.c\
		  routine.c\
		  shared.c\
		  time.c
OBJS 	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(LIB)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
