# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:05:52 by gyepark           #+#    #+#              #
#    Updated: 2021/12/29 00:14:46 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = conv_processor.c\
	   flags_processor.c\
	   ft_printf.c\
	   ft_printf_utils.c\
	   print_char.c\
	   print_format.c\
	   print_signed_int.c\
	   print_signed_int_conv_utils.c\
	   print_signed_int_left.c\
	   print_signed_int_right.c\
	   print_signed_int_utils.c\
	   print_string.c\
	   print_unsigned_int_dec.c\
	   print_unsigned_int_hex.c\
	   print_unsigned_int_hex_left.c\
	   print_unsigned_int_hex_right.c\
	   print_unsigned_int_utils.c\
	   print_unsigned_long_long.c\
	   print_unsigned_long_long_utils.c
B_SRCS = conv_processor_bonus.c\
		 flags_processor_bonus.c\
		 ft_printf_bonus.c\
		 ft_printf_utils_bonus.c\
		 print_char_bonus.c\
		 print_format_bonus.c\
		 print_signed_int_bonus.c\
		 print_signed_int_conv_utils_bonus.c\
		 print_signed_int_left_bonus.c\
		 print_signed_int_right_bonus.c\
		 print_signed_int_utils_bonus.c\
		 print_string_bonus.c\
		 print_unsigned_int_dec_bonus.c\
		 print_unsigned_int_hex_bonus.c\
		 print_unsigned_int_hex_left_bonus.c\
		 print_unsigned_int_hex_right_bonus.c\
		 print_unsigned_int_utils_bonus.c\
		 print_unsigned_long_long_bonus.c\
		 print_unsigned_long_long_utils_bonus.c
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = rc
RM = rm -f

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

$(B_OBJS) : $(B_SRCS)
	$(CC) -c $(CFLAGS) $(B_SRCS)
	$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)
	
all : $(NAME) bonus

bonus : $(B_OBJS)

clean :
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
