#include "so_long.h"

void free_map(t_game *game)
{
    for (int i = 0; i < game->height; i++)
        free(game->map[i]);
    free(game->map);
}


bool is_rectangular(t_game *game)
{
    for (int i = 0; i < game->height; i++)
    {
        int len = ft_strlen(game->map[i]) - (game->map[i][ft_strlen(game->map[i]) - 1] == '\n');
        if (len != game->width)
        {
            ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
            return false;
        }
    }
    return true;
}
bool walls(t_game *game)
{
    for (int i = 0; i < game->height; i++)
    {
        if (i == 0 || i == game->height - 1)
        {
            for (int j = 0; j < game->width; j++)
            {
                if (game->map[i][j] != '1')
                {
                    ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
                    return false;
                }
            }
        }
        else if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
        {
            ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
            return false;
        }
    }
    return true;
}


bool component(t_game *game)
{
    game->plyr_count = 0;
    game->coin_count = 0;
    game->exit_count = 0;

    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            if (game->map[i][j] == 'P')
            {
                game->plyr_x = j;
                game->plyr_y = i;
                game->plyr_count++;
            }
            else if (game->map[i][j] == 'E')
                game->exit_count++;
            else if (game->map[i][j] == 'C')
                game->coin_count++;
            else if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != '\n')
            {
                ft_putstr_fd("Error\nInvalid character in map.\n", 2);
                return false;
            }
        }
    }

    if (game->plyr_count != 1 || game->coin_count < 1 || game->exit_count != 1)
    {
        ft_putstr_fd("Error\nInvalid map components (P, C, E).\n", 2);
        return false;
    }

    return true;
}
static void free_map_copy(char **map, int height)
{
    for (int y = 0; y < height; y++) {
        free(map[y]);
    }
    free(map);
}
static char **copy_map(t_game *game)
{
    char **copy = malloc(sizeof(char *) * (game->height + 1));
    if (!copy)
        return NULL;

    for (int y = 0; y < game->height; y++)
    {
        copy[y] = ft_strdup(game->map[y]);
        if (!copy[y])
        {
            free_map_copy(copy, y);
            return NULL;
        }
    }
    copy[game->height] = NULL;
    return copy;
}


static void fill(t_game *game, char **map, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->height ||
    (map[y][x] == '1' || map[y][x] == 'F'))
    return;



    if (map[y][x] == 'C') 
        game->collected++;

    if (map[y][x] == 'E') 
        game->exit_reached = 1;

    map[y][x] = 'F';

    fill(game, map, x + 1, y);
    fill(game, map, x - 1, y);
    fill(game, map, x, y + 1);
    fill(game, map, x, y - 1);
}


static int flood_fill_check(t_game *game)
{
    char **map_copy = copy_map(game);
if (!map_copy)
    return false;


for (int i = 0; i < game->height; i++){
        ft_printf("%s\n", map_copy[i]);}


    game->collected = 0;
    game->exit_reached = 0;

    fill(game, map_copy, game->plyr_x, game->plyr_y);

    bool success = (game->collected == game->coin_count && game->exit_reached == 1);
    free_map_copy(map_copy, game->height);
    return success;
}


bool validate_map(t_game *game)
{
    if (!is_rectangular(game))
        return false;

    if (!walls(game))
        return false;

    if (!component(game))
        return false;


    if (!flood_fill_check(game))
    {
        ft_putstr_fd("Error\nNon esiste un percorso valido nella mappa.\n", 2);
        return false;
    }

    return true; 
}
