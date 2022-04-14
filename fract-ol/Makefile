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

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C mlx 2> /dev/null
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@make clean -C mlx
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

bonus : $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
