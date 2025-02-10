/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:15:25 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/10 15:17:29 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
#define WIDTH 512
#define HEIGHT 512
# include <stdlib.h>
# include<fcntl.h>
#include <stdbool.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

typedef struct s_images 
{
	mlx_image_t *player;
	mlx_image_t *collectible;
	mlx_image_t *exit;
	mlx_image_t *wall;
	mlx_image_t *floor;
} t_images;



typedef struct s_game 
{
	mlx_t *mlx;
	t_images *images;
	char	**map;
	int	player_x;
	int	player_y;

	int	moves;
	int	width;
	int	height;	
	 int player_count; 
    int coin_count; 
    int exit_count;

}	t_game;


void player_motor(t_game *game, int x, int y);
void input(mlx_key_data_t keydata, void *param);
bool is_map_valid(t_game *game);
void render_map(t_game *game);
mlx_image_t *char_to_image(t_game *game, char c);
t_images *load_images(t_game *game);
void initialization(t_game *game);
bool read_map(t_game *game, const char *file_path);
bool is_ber(char *str);
bool validate_map(t_game *game);
void free_map(t_game *game);
void free_images(t_images *images, mlx_t *mlx);
void render_player(t_game *game);

#endif
