#include"so_long.h"

void initialization(t_game *game)
{
    game->mlx = NULL;
    game->imgs = NULL;
    game->plyr_count = 0;
    game->coin_count = 0;
    game->exit_count = 0;
    game->map = NULL;
    game->plyr_x = 0;
    game->plyr_y = 0;
    game->moves = 0;
    game->width = 0;
    game->height = 0;
    game->collected = 0;
    game->exit_reached = 0;
}
void free_images(t_imgs *imgs, mlx_t *mlx)
{
    if (imgs->plyr)
        mlx_delete_image(mlx, imgs->plyr);
    if (imgs->coin)
        mlx_delete_image(mlx, imgs->coin);
    if (imgs->exit)
        mlx_delete_image(mlx, imgs->exit);
    if (imgs->wall)
        mlx_delete_image(mlx, imgs->wall);
    if (imgs->floor)
        mlx_delete_image(mlx, imgs->floor);
    free(imgs);
}

bool is_ber(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len < 4)
        return (false);
    return (str[len - 1] == 'r' && str[len - 2] == 'e'
        && str[len - 3] == 'b' && str[len - 4] == '.');
}
int check_game(int argc, char **argv, t_game *game)
{
    if (argc != 2)
    {
        ft_putstr_fd("Error\nCorrect usage one file .ber at a time : ./so_long <mappa.ber>\n", 2);
        return (EXIT_FAILURE);
    }
    if (!is_ber(argv[1]))
    {
        ft_putstr_fd("Error\nChoose a .ber extension\n", 2);
        return (EXIT_FAILURE);
    }
    initialization(game);
    if (!read_map(game, argv[1]) || !validate_map(game))
    {
        ft_putstr_fd("Error\nMap is invalid.\n", 2);
        free_map(game);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
bool read_map(t_game *game, const char *file_path)
{
    int fd;
    char *line;
    int line_count;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error\nCould not open map file\n", 2);
        return false;
    }

    game->map = ft_calloc(1024, sizeof(char *)); // Adatta la dimensione se necessario
    if (!game->map)
    {
        close(fd);
        return false;
    }

    line_count = 0;
    game->width = -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (game->width == -1)
            game->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n'); // Rimuove '\n'
        game->map[line_count++] = line;
    }
    close(fd);
    game->height = line_count;

    

    return true;
}