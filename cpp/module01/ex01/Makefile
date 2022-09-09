# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 01:45:03 by gyepark           #+#    #+#              #
#    Updated: 2022/09/08 01:45:04 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie_horde

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

SRCS	= Zombie.cpp\
		  zombieHorde.cpp\
		  main.cpp
OBJS	= $(SRCS:.cpp=.o)

all		: $(NAME)
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
$(OBJS)	: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
