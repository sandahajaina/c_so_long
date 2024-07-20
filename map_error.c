/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:09:23 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/20 16:09:24 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
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

int	check_map_character(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
		}
	}
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
