/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:56:51 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:56:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
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
	(void)game;
	exit(0);
	return (0);
}
