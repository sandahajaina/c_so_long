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

int	main(int argc, char *argv[])
{
	// void *mlx;
	// void *mlx_win;
	char **map;
	(void) argc;
	int fd;

	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		perror("error");
	map = read_map(fd);
	printf("%s\n", *map);
	// (void)mlx_win;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 200, 100, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}