/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:42:44 by sranaivo          #+#    #+#             */
/*   Updated: 2024/06/13 13:43:03 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}			t_game;

void	load_xpm(void *mlx, t_xpm *xpm)
{
	int	width;
	int	height;

	xpm->bg = mlx_xpm_file_to_image(mlx, "assets/bg.xpm", &width, &height);
	xpm->coin = mlx_xpm_file_to_image(mlx, "assets/coin.xpm", &width, &height);
	xpm->door = mlx_xpm_file_to_image(mlx, "assets/door.xpm", &width, &height);
	xpm->player = mlx_xpm_file_to_image(mlx, "assets/ninja.xpm", &width,
			&height);
	xpm->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &width, &height);
}

void	init_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	game->map.collectible = 0;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map.map[y][x] == 'C')
				game->map.collectible++;
			if (game->map.map[y][x] == 'P')
			{
				game->map.start.x = x;
				game->map.start.y = y;
			}
			if (game->map.map[y][x] == 'E')
			{
				game->map.exit.x = x;
				game->map.exit.y = y;
			}
		}
	}
}

t_game	init_game(char *file)
{
	t_game	game;
	int		x;
	int		y;

	game.mlx = mlx_init();
	game.map.map = read_map(file);
	x = 0;
	while (game.map.map[0][x] != '\n')
		x++;
	y = count_map_line(file);
	game.width = x;
	game.height = y;
	game.win = mlx_new_window(game.mlx, (game.width * 32), (game.height * 32),
			"so_long");
	load_xpm(game.mlx, &game.xpm);
	init_map(&game);
	return (game);
}

void	render_map(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map.map[y][x] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.bg, x * 32,
					y * 32);
			if (game.map.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.wall, x
					* 32, y * 32);
			if (game.map.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.coin, x
					* 32, y * 32);
			if (game.map.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.door, x
					* 32, y * 32);
			if (game.map.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.player, x
					* 32, y * 32);
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		/***********************************************************/
		t_game game;

		game = init_game(argv[1]);
		render_map(game);
		printf ("start = x: %d | y: %d\n", game.map.start.x, game.map.start.y);
		printf ("exit = x: %d | y: %d\n", game.map.exit.x, game.map.exit.y);
		mlx_loop(game.mlx);
		/**********************************************************/
	}
	return (0);
}