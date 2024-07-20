NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = so_long.c map.c ft_split.c utils.c ft_init.c ft_free.c
OBJS = $(SRCS:.c=.o)
LIB_PATH_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH_MLX) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re