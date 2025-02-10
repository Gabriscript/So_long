/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:20:27 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/10 15:14:10 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"


// Funzione per muovere il giocatore evitando errori
void player_motor(t_game *game, int x, int y) {
    int newx = game->player_x + x;
    int newy = game->player_y + y;
    //game->coin_count = game->counts->c_count; 
   

    if (newx < 0 || newy < 0 || newx >= game->width || newy >= game->height)
        return;
    if (game->map[newy][newx] == '1')
        return;
    if (game->map[newy][newx] == 'C') {
        game->coin_count--; 
        game->map[newy][newx] = '0';
        //mlx_delete_image(game->mlx, game->images->collectible);
        for (size_t i = 0; i < game->images->collectible->count; i++) {
    if (game->images->collectible->instances[i].x == newx * TILE_SIZE &&
        game->images->collectible->instances[i].y == newy * TILE_SIZE) {
        game->images->collectible->instances[i].enabled = false;
        break;  // Fermati dopo aver trovato il collectible corretto
    }
    ft_printf("Collectible picked up! Remaining: %d\n", game->coin_count);
}

    }
    if (game->map[newy][newx] == 'E' && game->coin_count == 0) {
        ft_printf("You won in %d moves!\n", game->moves);
        mlx_close_window(game->mlx);
        return;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[newy][newx] = 'P';
    game->player_x = newx;
    game->player_y = newy;
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);

    // Aggiorna la posizione dell'immagine del giocatore
    game->images->player->instances[0].x = newx * TILE_SIZE;
    game->images->player->instances[0].y = newy * TILE_SIZE;
}




/*void input(void *param) {
    t_game *game = (t_game *)param;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
   //if(mlx_key_hook(game->mlx, keys, NULL))
    {   void input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_W)
            player_motor(game, 0, -1);
        else if (keydata.key == MLX_KEY_S)
            player_motor(game, 0, 1);
        else if (keydata.key == MLX_KEY_A)
            player_motor(game, -1, 0);
        else if (keydata.key == MLX_KEY_D)
            player_motor(game, 1, 0);
    }
}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        player_motor(game, 0, -1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        player_motor(game, 0, 1);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        player_motor(game, -1, 0);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        player_motor(game, 1, );
}*/
void input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_W)
            player_motor(game, 0, -1);
        else if (keydata.key == MLX_KEY_S)
            player_motor(game, 0, 1);
        else if (keydata.key == MLX_KEY_A)
            player_motor(game, -1, 0);
        else if (keydata.key == MLX_KEY_D)
            player_motor(game, 1, 0);
    }
}
