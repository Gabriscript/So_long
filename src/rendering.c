/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:23:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/03 13:18:14 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


mlx_image_t	*char_to_image(char c, t_images *images)
{
	mlx_image_t *img = NULL;
	if (c == 'P')
		img = images->player;
	if (c == 'C')
		img = images->collectible;
	if (c == 'E')
		img = images->exit;
	if (c == '1')
		img =images->wall;
	if (c == '0')
		img = images->floor;
	return (img);
}

t_images	*load_images(mlx_t *mlx)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	images->player = mlx_texture_to_image(mlx, mlx_load_png("./assets/character.png"));
	if(!images->player)
		ft_printf("Error loading player image");
	images->collectible = mlx_texture_to_image(mlx, mlx_load_png("./assets/coin.png"));
	images->exit = mlx_texture_to_image(mlx, mlx_load_png("./assets/exit.png"));
	images->wall = mlx_texture_to_image(mlx, mlx_load_png("./assets/wall.png"));
	if(!images->wall)
		ft_printf("Error loading wall image");
	images->floor = mlx_texture_to_image(mlx, mlx_load_png("./assets/floor.png"));
	if (!images->player || !images->collectible || !images->exit
			||!images->wall || !images->floor)
	{
		free(images);
		ft_printf("Error\nImages not loaded correctly");
		exit(EXIT_FAILURE);
	}
	return (images);
}


void render_map(mlx_t *mlx, char **map, int width, int height, t_images *images)
{
    int x, y;
    char tile;
    mlx_image_t *img;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            tile = map[y][x];

            img = char_to_image(tile, images);
         if (img)
{
    ft_printf("Rendering image at (%d, %d)\n", x * TILE_SIZE, y * TILE_SIZE);  // Debugging
    mlx_image_to_window(mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}
else
{
    ft_printf("Error: Image for tile '%c' is NULL\n", tile);
}
            x++;
        }
        y++;
    }
}
