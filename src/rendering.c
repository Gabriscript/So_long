/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:23:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/11 17:06:59 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_imgs	*load_images(t_game *game)
{
	t_imgs	*imgs;

	imgs = malloc(sizeof(t_imgs));
	if (!imgs)
		return (NULL);
	imgs->plyr
		= mlx_texture_to_image(game->mlx, mlx_load_png("./as/character.png"));
	imgs->coin
		= mlx_texture_to_image(game->mlx, mlx_load_png("./as/coin.png"));
	imgs->exit
		= mlx_texture_to_image(game->mlx, mlx_load_png("./as/exit.png"));
	imgs->wall
		= mlx_texture_to_image(game->mlx, mlx_load_png("./as/wall.png"));
	imgs->floor
		= mlx_texture_to_image(game->mlx, mlx_load_png("./as/floor.png"));
	if (!imgs->plyr || !imgs->coin || !imgs->exit
		|| !imgs->wall || !imgs->floor)
	{
		ft_putstr_fd("Error: Images not loaded correctly\n", 2);
		free_images(imgs, game->mlx);
		return (NULL);
	}
	return (imgs);
}

void	render_player(t_game *game)
{
	mlx_image_to_window(game->mlx, game->imgs->plyr,
		game->plyr_x * TILE, game->plyr_y * TILE);
}

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
