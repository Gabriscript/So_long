/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:25:15 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 14:39:01 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization(t_game *game)
{
	game->mlx = NULL;
	game->imgs = NULL;
	game->plyr_count = 0;
	game->coin_count = 0;
	game->exit_count = 0;
	game->map = NULL;
	game->plyr_x = 0;
	game->plyr_y = 0;
	game->moves = 0;
	game->width = 0;
	game->height = 0;
	game->collected = 0;
	game->exit_reached = 0;
}

void	free_images(t_imgs *imgs, mlx_t *mlx)
{
	if (imgs)
	{
		if (imgs->plyr)
			mlx_delete_image(mlx, imgs->plyr);
		if (imgs->coin)
			mlx_delete_image(mlx, imgs->coin);
		if (imgs->exit)
			mlx_delete_image(mlx, imgs->exit);
		if (imgs->wall)
			mlx_delete_image(mlx, imgs->wall);
		if (imgs->floor)
			mlx_delete_image(mlx, imgs->floor);
		free(imgs);
	}
}

bool	is_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (false);
	return (str[len - 1] == 'r' && str[len - 2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.');
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

bool	init_game(t_game *game)
{
	game->mlx = mlx_init(game->width * TILE,
			game->height * TILE, "so_long", true);
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX init failed\n", 2);
		free_map(game);
		return (false);
	}
	game->imgs = load_images(game);
	if (!game->imgs)
	{
		free_map(game);
		mlx_terminate(game->mlx);
		return (false);
	}
	return (true);
}
