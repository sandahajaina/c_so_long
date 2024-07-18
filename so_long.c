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
	while (game.map.map[0][x])
		x++;
	y = 0;
	while (game.map.map[y])
		y++;
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

void	destroy_xpm(t_game *game)
{
	mlx_destroy_image(game->mlx, game->xpm.bg);
	mlx_destroy_image(game->mlx, game->xpm.wall);
	mlx_destroy_image(game->mlx, game->xpm.player);
	mlx_destroy_image(game->mlx, game->xpm.coin);
	mlx_destroy_image(game->mlx, game->xpm.door);
}

void	free_map(char **map)
{
	int i = 0;
	while (map[i])
		free (map[i++]);
	free(map[i]);
	free (map);
}

void	free_game(t_game *game)
{
	destroy_xpm(game);
	free_map(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	close_window(t_game *game)
{
	free_game(game);
	(void) game;
	exit (0);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		/***********************************************************/
		t_game game;

		game = init_game(argv[1]);
		render_map(game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
		/**********************************************************/
	}

	return (0);
}