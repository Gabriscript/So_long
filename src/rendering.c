/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:23:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 14:45:06 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	file_exists(const char *path)
{
	return (access(path, F_OK) == 0);
}

static mlx_texture_t	*load_texture_or_null(const char *path)
{
	if (file_exists(path))
		return (mlx_load_png(path));
	ft_putstr_fd("Error\nFile not found: ", 2);
	ft_putstr_fd((char *)path, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

static	mlx_image_t	*load_single_image(t_game *game, const char *path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = load_texture_or_null(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

t_imgs	*load_images(t_game *game)
{
	t_imgs	*imgs;

	imgs = malloc(sizeof(t_imgs));
	if (!imgs)
		return (NULL);
	imgs->plyr = load_single_image(game, "./as/character.png");
	imgs->coin = load_single_image(game, "./as/coin.png");
	imgs->exit = load_single_image(game, "./as/exit.png");
	imgs->wall = load_single_image(game, "./as/wall.png");
	imgs->floor = load_single_image(game, "./as/floor.png");
	if (!imgs->plyr || !imgs->coin || !imgs->exit
		|| !imgs->wall || !imgs->floor)
	{
		free_images(imgs, game->mlx);
		ft_putstr_fd("Error\nImage load failed\n", 2);
		return (NULL);
	}
	return (imgs);
}
