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

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void put_image_to_image(t_data *big_img, t_data *small_img, int x_offset, int y_offset)
{
    int x = 0;
    int y = 0;
    int color;
    int small_img_width = 32;
    int small_img_height = 32;

    while (y < small_img_height)
    {
        x = 0;
        while (x < small_img_width)
        {
            color = *(unsigned int*)(small_img->addr + (y * small_img->line_length + x * (small_img->bits_per_pixel / 8)));
            my_mlx_pixel_put(big_img, x + x_offset, y + y_offset, color);
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

/***********************************************************/
		
		void    *mlx;
		void    *win;
		t_data  small_img;
		t_data  big_img;
		int     width = 800;
		int     height = 600;
		int     img_width;
		int     img_height;

		mlx = mlx_init();

		win = mlx_new_window(mlx, width, height, "Display Image");

		small_img.img = mlx_xpm_file_to_image(mlx, "assets/knight_idle_anim_f0_32x32.xpm", &img_width, &img_height);
		if (!small_img.img)

		small_img.addr = mlx_get_data_addr(small_img.img, &small_img.bits_per_pixel, &small_img.line_length, &small_img.endian);

		big_img.img = mlx_new_image(mlx, width, height);
		big_img.addr = mlx_get_data_addr(big_img.img, &big_img.bits_per_pixel, &big_img.line_length, &big_img.endian);

		int y = 0;
		while (y < height)
		{
			int x = 0;
			while (x < width)
			{
				put_image_to_image(&big_img, &small_img, x, y);
				x += 32;
			}
			y += 32;
		}

		mlx_put_image_to_window(mlx, win, big_img.img, 0, 0);

		mlx_loop(mlx);

/**********************************************************/

	}
	return (0);
}