/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:58:00 by sranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 13:58:02 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.map[new_y][new_x] != '1')
	{
		if (game->map.map[new_y][new_x] == 'C')
			game->map.collectible--;
		game->map.map[game->map.start.y][game->map.start.x] = '0';
		if (game->map.collectible == 0)
		{
			game->map.map[game->map.exit.y][game->map.exit.x] = 'E';
		}
		game->nb_move++;
		ft_printf("Number of move: %d\n", game->nb_move);
		if (game->map.map[new_y][new_x] == 'E' && game->map.collectible == 0)
		{
			ft_printf("You win!\n");
			close_window(game);
		}
		game->map.map[new_y][new_x] = 'P';
		game->map.start.x = new_x;
		game->map.start.y = new_y;
		render_map(*game);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119)
		move_player(game, game->map.start.x, game->map.start.y - 1);
	else if (keycode == 115)
		move_player(game, game->map.start.x, game->map.start.y + 1);
	else if (keycode == 97)
		move_player(game, game->map.start.x - 1, game->map.start.y);
	else if (keycode == 100)
		move_player(game, game->map.start.x + 1, game->map.start.y);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	**map;

	if (argc == 2)
	{
		map = read_map(argv[1]);
		if (!map)
		{
			ft_printf("Error\n");
			exit(0);
		}
		is_valid_map(map);
		game = init_game(read_map(argv[1]));
		render_map(game);
		mlx_key_hook(game.win, handle_keypress, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
