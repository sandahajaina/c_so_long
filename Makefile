NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = so_long.c map.c ft_split.c utils.c ft_init.c ft_free.c map_error.c
OBJS = $(SRCS:.c=.o)
LIB_MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJS) ft_printf/libftprintf.a
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MLX) -Lft_printf -lftprintf -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

ft_printf/libftprintf.a :
	$(MAKE) -C ft_printf

clean :
	rm -f $(OBJS)
	$(MAKE) -C ft_printf clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

re : fclean all

.PHONY : all clean fclean re