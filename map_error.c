/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:33 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:57:35 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular_n_valid(char **map)
{
	int	width;
	int	i;

	if (!map || !map[0])
	{
		return (0);
	}
	width = ft_strlen(map[0]);
	if (width < 5)
		return (0);
	i = 0;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != width || i == width)
			return (0);
	}
	if (i < 3)
	{
		return (0);
	}
	return (1);
}

int	check_map_characters_player_exit(char **map)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = -1;
	player = 0;
	exit = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				player++;
		}
	}
	if (player != 1 || exit != 1)
		return (0);
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int	width;
	int	height;
	int	i;

	width = 0;
	height = 0;
	i = 0;
	while (map[0][width])
		width++;
	while (map[height])
		height++;
	i = -1;
	while (++i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_collectible(char **map)
{
	int	i;
	int	j;
	int	collectible;

	collectible = 0;
	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				collectible++;
		}
	}
	if (collectible < 1)
		return (0);
	return (1);
}

void	is_valid_map(char **map)
{
	if (!is_rectangular_n_valid(map))
		ft_error(map, "The map is not rectangular or is invalid.");
	if (!is_surrounded_by_walls(map))
		ft_error(map, "The walls are not correct.");
	if (!check_map_characters_player_exit(map))
		ft_error(map, "Missing element (player | exit)");
	if (!check_map_collectible(map))
		ft_error(map, "There are no collectibles");
	if (!is_valid_path(map))
		ft_error(map, "There is no valid path to complete the game");
	free_map(map);
}
