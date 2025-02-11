/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:20:27 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/11 17:13:21 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"



void	plyr_motor(t_game *game, int x, int y)
{
    int	newx;
    int	newy;

    newx = game->plyr_x + x;
    newy = game->plyr_y + y;
    if (newx < 0 || newy < 0 || newx >= game->width || newy >= game->height)
	    return ;
    if (game->map[newy][newx] == '1')
	    return ;
    if (game->map[newy][newx] == 'C')
    {
	    game->coin_count--;
	    game->map[newy][newx] = '0';
	    for (size_t i = 0; i < game->imgs->coin->count; i++) {
    if (game->imgs->coin->instances[i].x == newx * TILE &&
        game->imgs->coin->instances[i].y == newy * TILE) {
        game->imgs->coin->instances[i].enabled = false;
        break;  // Fermati dopo aver trovato il coin corretto
    }
    ft_printf("coin picked up! Remaining: %d\n", game->coin_count);
    if(game->coin_count == 0)
        ft_printf("the gate is open: %d\n", game->exit_count);
}

    }
    if (game->map[newy][newx] == 'E' && game->coin_count == 0) {
        ft_printf("You won in %d moves!\n", game->moves);
        mlx_close_window(game->mlx);
        return;
    }
    game->map[game->plyr_y][game->plyr_x] = '0';
    game->map[newy][newx] = 'P';
    game->plyr_x = newx;
    game->plyr_y = newy;
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);

    // Aggiorna la posizione dell'immagine del giocatore
    game->imgs->plyr->instances[0].x = newx * TILE;
    game->imgs->plyr->instances[0].y = newy * TILE;
}

void input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_W)
            plyr_motor(game, 0, -1);
        else if (keydata.key == MLX_KEY_S)
            plyr_motor(game, 0, 1);
        else if (keydata.key == MLX_KEY_A)
            plyr_motor(game, -1, 0);
        else if (keydata.key == MLX_KEY_D)
            plyr_motor(game, 1, 0);
    }
}
