#include"so_long.h"

void initialization(t_game *game)
{
    game->mlx = NULL;
    game->images = NULL;
    game->player_count = 0;
    game->coin_count = 0;
    game->exit_count = 0;
    game->map = NULL;
    game->player_x = 0;
    game->player_y = 0;
    game->moves = 0;
    game->width = 0;
    game->height = 0;
}
void free_images(t_images *images, mlx_t *mlx)
{
    if (images->player)
        mlx_delete_image(mlx, images->player);
    if (images->collectible)
        mlx_delete_image(mlx, images->collectible);
    if (images->exit)
        mlx_delete_image(mlx, images->exit);
    if (images->wall)
        mlx_delete_image(mlx, images->wall);
    if (images->floor)
        mlx_delete_image(mlx, images->floor);

    free(images); // Libera la struttura t_images
}

bool is_ber(char *str)
{
     int len = ft_strlen(str);
     if (len < 4)
          return (false);
     return (str[len - 1] == 'r' && str[len - 2] == 'e' 
          && str[len - 3] == 'b' && str[len - 4] == '.');
}
