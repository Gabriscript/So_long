/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:23:31 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/10 14:28:18 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


mlx_image_t *char_to_image(t_game *game, char c)
{
    mlx_image_t *img = NULL;

    if (c == 'P')
        img = game->images->player;
    else if (c == 'C')
        img = game->images->collectible;
    else if (c == 'E')
        img = game->images->exit;
    else if (c == '1')
        img = game->images->wall;
    else if (c == '0')
        img = game->images->floor;

    return img;
}


// Caricamento delle immagini con gestione della memoria
t_images *load_images(t_game *game)
{
    t_images *images = malloc(sizeof(t_images));
    if (!images) return NULL;

    images->player = mlx_texture_to_image(game->mlx, mlx_load_png("./assets/character.png"));
    images->collectible = mlx_texture_to_image(game->mlx, mlx_load_png("./assets/coin.png"));
    images->exit = mlx_texture_to_image(game->mlx, mlx_load_png("./assets/exit.png"));
    images->wall = mlx_texture_to_image(game->mlx, mlx_load_png("./assets/wall.png"));
    images->floor = mlx_texture_to_image(game->mlx, mlx_load_png("./assets/floor.png"));

    if (!images->player || !images->collectible || !images->exit || !images->wall || !images->floor) {
        ft_printf("Error: Images not loaded correctly\n");
        free_images(images, game->mlx);
        return NULL;
    }
    return images;
}




void render_player(t_game *game)
{
    mlx_image_to_window(game->mlx, game->images->player,  game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void render_map(t_game *game)
{
    int x, y;
    char tile;

    for (y = 0; y < game->height; y++)
    {
        for (x = 0; x < game->width; x++)
        {
            tile = game->map[y][x];
            mlx_image_to_window(game->mlx, game->images->floor, x * TILE_SIZE, y * TILE_SIZE);
            
            if (tile == '1')
                mlx_image_to_window(game->mlx, game->images->wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'C')
                mlx_image_to_window(game->mlx, game->images->collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'E')
                mlx_image_to_window(game->mlx, game->images->exit, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'P')
            {
                tile = game->map[y][x];
                mlx_image_to_window(game->mlx, game->images->floor, x * TILE_SIZE, y * TILE_SIZE);
                game->player_x = x;
                game->player_y = y;
            }
        }
    }
}



