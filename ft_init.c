/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:22:16 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/20 13:22:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				game->map.map[y][x] = '0';
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
	game.nb_move = 0;
	return (game);
}

static void	draw_map(t_game *game, int *x, int *y)
{
	if (game->map.map[*y][*x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.bg, *x * 32, *y
			* 32);
	if (game->map.map[*y][*x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.wall, *x * 32,
			*y * 32);
	if (game->map.map[*y][*x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.coin, *x * 32,
			*y * 32);
	if (game->map.map[*y][*x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.door, *x * 32,
			*y * 32);
	if (game->map.map[*y][*x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.player, *x * 32,
			*y * 32);
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
			draw_map(&game, &x, &y);
			x++;
		}
		y++;
	}
}
