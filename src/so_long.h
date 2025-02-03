/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:15:25 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/03 10:57:40 by ggargani         ###   ########.fr       */
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

typedef struct s_counts
 {
    int p_count; 
    int c_count; 
    int e_count; 
} t_counts;

typedef struct s_game 
{
	mlx_t *mlx;
	t_images *images;
	char	**map;
	int	player_x;
	int	player_y;
	int	collectibles;
	int	moves;
	int	width;
	int	height;	

}	t_game;


void    player_motor(t_game *game, int x, int y);
void	input(void *param);
bool is_map_valid(const char *map_path);
void	render_map(mlx_t *mlx, char **map,	int width, int height, t_images *images);
mlx_image_t	*char_to_image(char c, t_images *images);
t_images	*load_images(mlx_t *mlx);
void    init_value(t_counts *count);
char **read_map(const char *file_path, int *width, int *height);
bool is_ber(char *str);
#endif
