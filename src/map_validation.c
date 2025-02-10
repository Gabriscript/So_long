#include "so_long.h"
#include <stdio.h>
bool read_map(t_game *game, const char *file_path)
{
    int fd;
    char *line;
    int line_count;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        ft_printf("Error\nCould not open map file: %s\n", file_path);
        return false;
    }

    game->map = ft_calloc(1024, sizeof(char *)); // Adjust size if needed
    if (!game->map)
    {
        close(fd);
        return false;
    }

    line_count = 0;
    game->width = -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("Read line: %s", line);
        if (game->width == -1)
            game->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n'); // Remove '\n'
        game->map[line_count++] = line;
    }

    close(fd);
    game->height = line_count;

    return true;
}


void free_map(t_game *game)
{
    int i;

    i = 0;
    while( i < game->height)
    {
        free(game->map[i]);
    }
    free(game->map);

}
bool is_rectangular(t_game *game)
{
    int i;
    int len;

    i = 0;
    while (game->map[i])
    {
        len = ft_strlen(game->map[i]) - (game->map[i][ft_strlen(game->map[i]) - 1] == '\n'); // Adjust for '\n'
        if (len != game->width)
        {
            ft_printf("Error\nMap is not rectangular.\n");
            return (false);
        }
        i++;
    }
    return (true);
}


bool walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->height)
    {
        if (i == 0 || i == game->height - 1)
        {
            j = 0;
            while (j < game->width)
            {
                if (game->map[i][j] != '1')
                {
                    ft_printf("Error\nMap is not surrounded by walls.\n");
                    return (false);
                }
                j++;
            }
        }
        else
        {
            if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
            {
                ft_printf("Error\nMap is not surrounded by walls.\n");
                return (false);
            }
        }
        i++;
    }
    return (true);
}


bool component(t_game *game)
{
   
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'P')
               game->player_count++;
            else if (game->map[i][j] == 'E')
               game->exit_count++;
            else if (game->map[i][j] == 'C')
               game->coin_count++;
            else if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != '\n')
            {
                ft_printf("Error\nInvalid character in map: '%c'.\n", game->map[i][j]);
                return (false);
            }
            j++;
        }
        i++;
    }
    if (game->player_count != 1 ||game->coin_count < 1 ||game->exit_count != 1)
    {
        ft_printf("Error\nInvalid map components (P, C, E).\n");
        ft_printf("PLayer : %d\nCollectibles : %d\n Exit : %d",game->player_count,game->coin_count,game->exit_count);
        return (false);
    }
    return (true);
}

/*bool is_map_valid(const char *map_path)
{
    char    **map;
    int     width;
    int     height;

    map = read_map(map_path, &width, &height);
    if (!map)
            return (false);
    if (!is_rectangular(map, width) || !walls(map, height, width) || !component(map))
    {
        free_map(map, height);
        return (false);
    }
    free_map(map, height);
    return (true);
}*/
/*static void fill(char **tab, t_point size, int x, int y, char target, int *collected, int *exit_reached)
{
    if (x < 0 || y < 0 || x >= size.x || y >= size.y || (tab[y][x] != target && tab[y][x] != 'C' && tab[y][x] != 'E'))
        return;

    if (tab[y][x] == 'C') 
        (*collected)++;  // Conta i collezionabili trovati

    if (tab[y][x] == 'E') 
        (*exit_reached) = 1;  // Segna che l'uscita è stata raggiunta

    tab[y][x] = 'F';  // Segna come visitato

   
    fill(tab, size, x + 1, y, target, collected, exit_reached);
    fill(tab, size, x - 1, y, target, collected, exit_reached);
    fill(tab, size, x, y + 1, target, collected, exit_reached);
    fill(tab, size, x, y - 1, target, collected, exit_reached);
}

static int flood_fill_check(char **tab, t_point size, t_point begin, int total_collectibles)
{
    int collected = 0;
    int exit_reached = 0;
    char target = tab[begin.y][begin.x];

    if (target == '1')
        return (0);

    fill(tab, size, begin.x, begin.y, target, &collected, &exit_reached);

    return (collected == total_collectibles && exit_reached);
}*/


bool validate_map(t_game *game)
{
    // Controlla se la mappa è rettangolare
    if (!is_rectangular(game))
    {
        ft_printf("Error\nLa mappa non è rettangolare.\n");
        return false;
    }

    // Controlla se la mappa è chiusa da muri
    if (!walls(game))
    {
        ft_printf("Error\nLa mappa non è circondata da muri.\n");
        return false;
    }

    // Controlla se la mappa ha almeno un'uscita, un giocatore e un collezionabile
    if (!component(game))
    {
        ft_printf("Error\nLa mappa non ha i componenti minimi richiesti.\n");
        return false;
    }

    // Controllo del pathfinding: verifica se il giocatore può raccogliere tutto e raggiungere l'uscita
  //  if (!flood_fill_check(map, t_point){width, height}, find_player(map), count_collectibles(map)))
    //{
      //  ft_printf("Error\nNon esiste un percorso valido nella mappa.\n");
        //return false;
   // }

    return true; // Mappa valida!
}
