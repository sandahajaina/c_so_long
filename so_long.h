/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:43:11 by sranaivo          #+#    #+#             */
/*   Updated: 2024/06/13 13:43:14 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_xpm
{
	void	*bg;
	void	*coin;
	void	*door;
	void	*player;
	void	*wall;
}			t_xpm;

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_map
{
	char	**map;
	int		collectible;
	t_coord	start;
	t_coord	exit;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_xpm	xpm;
	t_map	map;
    int     nb_move;
}			t_game;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "ft_printf/ft_printf.h"

//ft_init.c
void	render_map(t_game game);
t_game	init_game(char **map);
void	init_map(t_game *game);
void	load_xpm(void *mlx, t_xpm *xpm);

//ft_free.c
int	close_window(t_game *game);
void	free_game(t_game *game);
void	free_map(char **map);
void	destroy_xpm(t_game *game);

//so_long.c (main)
void	move_player(t_game *game, int new_x, int new_y);
int	    handle_keypress(int keycode, t_game *game);

//map.c
int		count_map_line(char *map);
char    **read_map(char *map);
char	*get_map_content(char *file);

//map_error.c
int	is_rectangular(char **map);
int	check_map_character(char **map);
int	is_surrounded_by_walls(char **map);

//ft_split
char	**ft_split(char const *s, char c);

//utils.c
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
