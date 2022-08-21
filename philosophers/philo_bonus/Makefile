# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 23:19:26 by gyepark           #+#    #+#              #
#    Updated: 2022/08/16 00:34:06 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo_bonus

CC 		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -g
LIB		= 	-pthread
RM		= 	rm -f

SRCS 	=	arguments.c\
			construct.c\
			core.c\
			cycle.c\
			destruct.c\
			handle.c\
			main.c\
			monitor.c\
			monitor_semaphore.c\
			naming.c\
			philo_semaphore.c\
			shared.c\
			subprocess.c\
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
