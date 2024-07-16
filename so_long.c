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

typedef struct	s_xpm
{
	void	*bg;
	void	*coin;
	void	*door;
	void	*player;
	void	*wall;
}				t_xpm;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_xpm	xpm;
}				t_game;

void	load_xpm(void *mlx, t_xpm *xpm)
{
	int		width;
	int		height;

	xpm->bg = mlx_xpm_file_to_image(mlx, "assets/bg.xpm", &width, &height);
	xpm->coin = mlx_xpm_file_to_image(mlx, "assets/coin.xpm", &width, &height);
	xpm->door = mlx_xpm_file_to_image(mlx, "assets/door.xpm", &width, &height);
	xpm->player = mlx_xpm_file_to_image(mlx, "assets/ninja.xpm", &width, &height);
	xpm->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &width, &height);
}

void	draw_map(char **map)
{
	void    *mlx;
		void	*win;
		t_xpm	xpm;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 900, 600, "so_long");
		load_xpm(mlx, &xpm);
	//printf ("%c\n", map[0][0]);
	int x = 0;
	int y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 34)
		{
			if (map[x][y] == '1')
			{
				mlx_put_image_to_window(mlx, win, xpm.door, (x*32), (y*32));
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	char **map;

	if (argc == 2)
	{
		map = NULL;
		map = read_map(argv[1]);

		printf("%c\n", map[0][0]);

/***********************************************************/
		
		void    *mlx;
		void	*win;
		t_xpm	xpm;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 900, 600, "so_long");
		load_xpm(mlx, &xpm);

		draw_map(map);

		mlx_loop(mlx);
/**********************************************************/

	}
	return (0);
}