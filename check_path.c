/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:52:54 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:53:03 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_tab(char **tab, int x, int y, char wall)
{
	if (tab[y][x] == wall || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	fill_tab(tab, x - 1, y, wall);
	fill_tab(tab, x + 1, y, wall);
	fill_tab(tab, x, y - 1, wall);
	fill_tab(tab, x, y + 1, wall);
}

static void	get_player_position(char **tab, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
		}
	}
}

int	is_valid_path(char **tab)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_position(tab, &x, &y);
	fill_tab(tab, x, y, '1');
	i = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
				return (0);
		}
	}
	return (1);
}
