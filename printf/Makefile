# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:05:52 by gyepark           #+#    #+#              #
#    Updated: 2021/12/15 17:11:11 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTDIR = libft
LIBFTARC = libft.a
SRCS = ft_printf.c print_c.c print_di.c print_flag.c\
	  print_hex.c print_p.c print_s.c print_u.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = rc
RM = rm -f

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR) all
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(LIBFTDIR)/*.o

$(OBJS) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

all : $(NAME)

clean :
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(LIBFTARC)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
