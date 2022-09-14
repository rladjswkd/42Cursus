# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 01:45:03 by gyepark           #+#    #+#              #
#    Updated: 2022/09/14 20:11:57 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= program

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
RM		= rm -f

SRCS	= AMateria.cpp\
		  Character.cpp\
		  Cure.cpp\
		  Ice.cpp\
		  MateriaSource.cpp\
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
