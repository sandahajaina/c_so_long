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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char *argv[])
{
	char **map;

	if (argc == 2)
	{
		map = NULL;
		map = read_map(argv[1]);

/***********************************************************/
		
		void	*mlx;
		void	*mlx_win;
		t_data	img;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 900, 600, "Hello world!");
		img.img = mlx_new_image(mlx, 900, 600);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		int x = 5;
		int y = 5;
		while (x < 50)
		{
			my_mlx_pixel_put(&img, x++, y, 0x00FF0000);
			my_mlx_pixel_put(&img, x, 50, 0x00FF0000);
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);

/**********************************************************/

	}
	return (0);
}