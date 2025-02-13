/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:20:27 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 14:31:53 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_coin(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	if (game->map[y][x] == 'C')
	{
		game->coin_count--;
		game->map[y][x] = '0';
		while (i < game->imgs->coin->count)
		{
			if (game->imgs->coin->instances[i].x == x * TILE
				&& game->imgs->coin->instances[i].y == y * TILE)
			{
				game->imgs->coin->instances[i].enabled = false;
				break ;
			}
			i++;
		}
	}
}

static bool	handle_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->coin_count == 0)
		{
			ft_printf("You won in %d moves!\n", game->moves);
			mlx_close_window(game->mlx);
			return (true);
		}
	}
	return (false);
}

static void	update_player_position(t_game *game, int x, int y)
{
	char	prev_tile;

	prev_tile = game->map[game->plyr_y][game->plyr_x];
	if (prev_tile == 'E')
		game->map[game->plyr_y][game->plyr_x] = 'E';
	else
		game->map[game->plyr_y][game->plyr_x] = '0';
	if (x != game->exit_x || y != game->exit_y)
		game->map[y][x] = 'P';
	game->plyr_x = x;
	game->plyr_y = y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->imgs->plyr->instances[0].x = x * TILE;
	game->imgs->plyr->instances[0].y = y * TILE;
}

static void	player_motor(t_game *game, int x, int y)
{
	int	newx;
	int	newy;

	newx = game->plyr_x + x;
	newy = game->plyr_y + y;
	if (newx < 0 || newy < 0 || newx >= game->width || newy >= game->height)
		return ;
	if (game->map[newy][newx] == '1')
		return ;
	handle_coin(game, newx, newy);
	if (handle_exit(game, newx, newy))
		return ;
	update_player_position(game, newx, newy);
}

void	input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			player_motor(game, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			player_motor(game, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			player_motor(game, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			player_motor(game, 1, 0);
	}
}
