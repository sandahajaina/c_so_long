NAME = so_long
CC = clang
CFLAGS = -Wall -Werror -Wextra
SRCS = so_long.c map.c draw_map.c ft_split.c utils.c
OBJS = $(SRCS:.c=.o)
LIB_PATH_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH_MLX) -o $(NAME)

# get_next_line/gnl.a :
# 	$(MAKE) -C get_next_line

%.o : %.c
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re