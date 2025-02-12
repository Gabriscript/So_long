/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:15:25 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 18:28:52 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 64
# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

typedef struct s_imgs
{
	mlx_image_t	*plyr;
	mlx_image_t	*coin;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
}	t_imgs;

typedef struct s_game
{
	int			plyr_x;
	int			plyr_y;
	int			moves;
	int			width;
	int			height;	
	int			plyr_count;
	int			coin_count;
	int			exit_count;
	int			collected;
	int			exit_reached;
	int			exit_y;
	int			exit_x;
	char		**map;
	mlx_t		*mlx;
	t_imgs		*imgs;
}	t_game;

int				check_game(int argc, char **argv, t_game *game);
bool			is_map_valid(t_game *game);
bool			is_ber(char *str);
bool			read_map(t_game *game, const char *file_path);
bool			is_rectangular(t_game *game);
bool			walls(t_game *game);
bool			has_all_components(t_game *game);
bool			validate_map(t_game *game);
void			input(mlx_key_data_t keydata, void *param);
void			render_map(t_game *game);
void			initialization(t_game *game);
void			free_map(t_game *game);
void			free_images(t_imgs *images, mlx_t *mlx);
void			render_player(t_game *game);
t_imgs			*load_images(t_game *game);
mlx_image_t		*char_to_image(t_game *game, char c);

#endif