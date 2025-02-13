/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:37:04 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 14:41:56 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_to_window(game->mlx, game->imgs->floor, x * TILE, y * TILE);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->imgs->wall, x * TILE, y * TILE);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->imgs->coin, x * TILE, y * TILE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->imgs->exit, x * TILE, y * TILE);
	else if (tile == 'P')
	{
		game->plyr_x = x;
		game->plyr_y = y;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	mlx_image_to_window(game->mlx, game->imgs->plyr,
		game->plyr_x * TILE, game->plyr_y * TILE);
}

mlx_image_t	*char_to_image(t_game *game, char c)
{
	mlx_image_t	*img;

	img = NULL;
	if (c == 'P')
		img = game->imgs->plyr;
	else if (c == 'C')
		img = game->imgs->coin;
	else if (c == 'E')
		img = game->imgs->exit;
	else if (c == '1')
		img = game->imgs->wall;
	else if (c == '0')
		img = game->imgs->floor;
	return (img);
}
