# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:46:08 by gyepark           #+#    #+#              #
#    Updated: 2022/02/22 14:30:08 by gyepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
COMMON_SRCS = utils.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(SERVER_NAME) $(CLIENT_NAME)

bonus : all

$(SERVER_NAME) : $(SERVER_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(COMMON_OBJS)

$(CLIENT_NAME) : $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(COMMON_OBJS)

$(SERVER_OBJS) : $(SERVER_SRCS)
	$(CC) $(CFLAGS) -c $(SERVER_SRCS)

$(CLIENT_OBJS) : $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -c $(CLIENT_SRCS)

$(COMMON_OBJS) : $(COMMON_SRCS)
	$(CC) $(CFLAGS) -c $(COMMON_SRCS)

clean :
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(COMMON_OBJS)

fclean : clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
