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
		void	*win;
		void	*img;
		int		width;
		int		height;
		t_data	big_img;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 900, 600, "so_long");
		img = mlx_xpm_file_to_image(mlx, "assets/ninja.xpm", &width, &height);

		big_img.img = mlx_new_image(mlx, 900, 600);
		big_img.addr = mlx_get_data_addr(big_img.img, &big_img.bits_per_pixel,
			&big_img.line_length, &big_img.endian);

		mlx_put_image_to_window(mlx, win, img, 5, 5);

		mlx_loop(mlx);
/**********************************************************/

	}
	return (0);
}