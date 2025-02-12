/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:03:06 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 18:28:59 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int open_map_file(const char *file_path)
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        ft_putstr_fd("Error\nCould not open map file\n", 2);
    return (fd);
}

static bool allocate_map(t_game *game)
{
    game->map = ft_calloc(1024, sizeof(char *)); // Adatta la dimensione se necessario
    if (!game->map)
    {
        ft_putstr_fd("Error\nMemory allocation failed for map\n", 2);
        return (false);
    }
    return (true);
}

static bool read_map_lines(t_game *game, int fd)
{
    char *line;
    int line_count;

    line_count = 0;
    game->width = -1;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (game->width == -1)
            game->width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n'); // Rimuove '\n'
        game->map[line_count++] = line;
    }
    game->height = line_count;

    if (line_count == 0 || game->width <= 0)
    {
        ft_putstr_fd("Error\nMap is empty or invalid\n", 2);
        return (false);
    }    
    return (true);
}

bool read_map(t_game *game, const char *file_path)
{
    int fd;

    fd = open_map_file(file_path);
    if (fd < 0)
        return (false);
    if (!allocate_map(game))
    {
        close(fd);
        return (false);
    }
    if (!read_map_lines(game, fd))
    {
        close(fd);
        free_map(game);
        return (false);
    }
    close(fd);
    return (true);
}