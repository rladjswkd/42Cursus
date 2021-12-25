# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:05:52 by gyepark           #+#    #+#              #
#    Updated: 2021/12/25 23:03:03 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c\
	   print_signed_int.c\
	   print_unsigned_int_dec.c print_unsigned_int_hex.c\
	   print_unsigned_int_hex_left_aligned.c print_unsigned_int_hex_right_aligned.c\
	   print_unsigned_long_long.c print_string.c print_char.c\
	   ft_printf_utils.c print_unsigned_long_long_utils.c print_unsigned_int_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = rc
RM = rm -f

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
