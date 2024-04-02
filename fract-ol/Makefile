NAME = fractol
SRCS = color.c\
       draw.c\
       fractal.c\
       handler.c\
       main.c\
       newton_fractal.c\
       newton_math.c\
       status.c\
       utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
UNAME = $(shell uname)

%.o : %.c
#	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@
ifeq ($(UNAME), Linux)
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	$(CC) -Imlx -O3 -c $< -o $@
endif

all : $(NAME)

$(NAME) : $(OBJS)
ifeq ($(UNAME), Linux)
	@make -C mlx_linux 2> /dev/null
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
else	
	@make -C mlx 2> /dev/null
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
endif

clean :
	@make clean -C mlx
	@make clean -C mlx_linux
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

bonus : $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
