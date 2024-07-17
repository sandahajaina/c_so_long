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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	t_xpm	xpm;
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

t_game	init_game(char *file)
{
	t_game	game;
	int		x;
	int		y;

	game.mlx = mlx_init();
	game.map = read_map(file);
	x = 0;
	while (game.map[0][x] != '\n')
		x++;
	y = count_map_line(file);
	printf("\n");
	game.width = x;
	game.height = y;
	game.win = mlx_new_window(game.mlx, (game.width * 32), (game.height * 32),
			"so_long");
	load_xpm(game.mlx, &game.xpm);
	return (game);
}

void	render_game(t_game game)
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
			if (game.map[y][x] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.bg, x * 32,
					y * 32);
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.wall, x
					* 32, y * 32);
			if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.coin, x
					* 32, y * 32);
			if (game.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.xpm.door, x
					* 32, y * 32);
			if (game.map[y][x] == 'P')
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
		render_game(game);
		mlx_loop(game.mlx);
		/**********************************************************/
	}
	return (0);
}