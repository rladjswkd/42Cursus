# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:05:52 by gyepark           #+#    #+#              #
#    Updated: 2021/12/17 16:01:13 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = libft
LIBFTARC = libft.a
SRCS = ft_printf.c\
	   print_signed_int.c print_unsigned_int.c print_unsigned_long_long.c\
	   print_others.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = rc
RM = rm -f

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR) all
	mv $(LIBFTDIR)/$(LIBFTARC) .
	$(AR) $(ARFLAGS) $(LIBFTARC) $(OBJS)
	mv $(LIBFTARC) $(NAME)

$(OBJS) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

all : $(NAME)

clean :
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
