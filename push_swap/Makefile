# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:46:08 by gyepark           #+#    #+#              #
#    Updated: 2022/02/21 11:38:00 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
SRCS = ops_utils.c\
       ops_utils2.c\
       optimized_operations.c\
       push_swap.c\
       sort_direct.c\
       sort_direct_utils.c\
       sort_greedy.c
B_SRCS = checker.c\
	 checker_utils.c\
	 line_getter.c
C_SRCS = basic_operations.c\
	 input_manager.c\
	 printers.c\
	 program_manager.c\
	 stack_initializer.c\
	 stack_utils.c
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

$(NAME) : $(OBJS) $(C_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(C_OBJS)

all : $(NAME) $(B_NAME)

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJS) $(C_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS) $(C_OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(B_OBJS) : $(B_SRCS)
	$(CC) $(CFLAGS) -c $(B_SRCS)

$(C_OBJS) : $(C_SRCS)
	$(CC) $(CLFAGS) -c $(C_SRCS)

clean :
	$(RM) $(OBJS) $(B_OBJS) $(C_OBJS)

fclean : clean
	$(RM) $(NAME) $(B_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
