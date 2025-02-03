/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:20:27 by ggargani          #+#    #+#             */
/*   Updated: 2024/12/27 10:46:38 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


void    player_motor(t_game *game, int x, int y)
{
    int newx;
    int newy;

    newx = game->player_x + x;
    newy = game->player_y + y;

    if (game->map[newx][newy] == '1')
        return ;
     if (game->map[newx][newy] == 'C')
     {
         game->collectibles--;
         game->map[newy][newx] = '0';
     }
        
   if (game->map[newx][newy] == 'E' && game->collectibles == 0)
        mlx_close_window(game->mlx);

       game->map[game->player_y][game->player_x] = '0';
    game->map[newy][newx] = 'P';
    game->player_x = newx;
    game->player_y = newy;
    game->moves++;

    // Re-render map
    //render_map(game.mlx, map, width, height, game.images);
}



void	input(void *param)
{
	t_game *game = (t_game *)param;

	game->mlx = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		player_motor(game, 0, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		player_motor(game, 0, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		 player_motor(game, -1, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		 player_motor(game, 1, 0);
}
