NAME = so_long
CC = clang
CFLAGS = -Wall -Werror -Wextra
SRCS = so_long.c read_map.c
OBJS = $(SRCS:.c=.o)
LIB_PATH_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIB_PATH_GNL = -Lget_next_line -lgnl

all : $(NAME)

$(NAME) : $(OBJS) get_next_line/gnl.a
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH_MLX) get_next_line/gnl.a -o $(NAME)

get_next_line/gnl.a :
	$(MAKE) -C get_next_line

%.o : %.c
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C get_next_line clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C get_next_line fclean

re : fclean all

.PHONY : all clean fclean re