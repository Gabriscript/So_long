#include "so_long.h"
#include <stdio.h>
char **read_map(const char *file_path, int *width, int *height)
{
    int     fd;
    char    *line;
    char    **map;
    int     line_count;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        ft_printf("Error\nCould not open map file: %s\n", file_path);
        return (NULL);
    }
    map = ft_calloc(1024, sizeof(char *)); // Adjust size if needed
    if (!map)
    {
        close(fd);
        return (NULL);
    }
    line_count = 0;
    *width = -1;
    line = get_next_line(fd);
    while (line)
    {
        ft_printf("Read line: %s", line);
        if (*width == -1)
            *width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n'); // Remove '\n'
        map[line_count++] = line;
        line = get_next_line(fd);
    }
    close(fd);
    *height = line_count;
    return (map);
}

void free_map(char **map, int height)
{
    int i;

    i = 0;
    while( i < height)
    {
        free(map[i]);
    }
    free(map);
}

bool is_rectangular(char **map, int width)
{
    int i;
    int len;

    i = 0;
    while (map[i])
    {
        len = ft_strlen(map[i]) - (map[i][ft_strlen(map[i]) - 1] == '\n'); // Adjust for '\n'
        if (len != width)
        {
            ft_printf("Error\nMap is not rectangular.\n");
            return (false);
        }
        i++;
    }
    return (true);
}


bool walls(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        if (i == 0 || i == height - 1)
        {
            j = 0;
            while (j < width)
            {
                if (map[i][j] != '1')
                {
                    ft_printf("Error\nMap is not surrounded by walls.\n");
                    return (false);
                }
                j++;
            }
        }
        else
        {
            if (map[i][0] != '1' || map[i][width - 1] != '1')
            {
                ft_printf("Error\nMap is not surrounded by walls.\n");
                return (false);
            }
        }
        i++;
    }
    return (true);
}


bool component(char **map)
{
    t_counts    counts;
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
                counts.p_count++;
            else if (map[i][j] == 'E')
                counts.e_count++;
            else if (map[i][j] == 'C')
                counts.c_count++;
            else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
            {
                ft_printf("Error\nInvalid character in map: '%c'.\n", map[i][j]);
                return (false);
            }
            j++;
        }
        i++;
    }
    if (counts.p_count != 1 || counts.c_count < 1 || counts.e_count != 1)
    {
        ft_printf("Error\nInvalid map components (P, C, E).\n");
        return (false);
    }
    return (true);
}

bool is_map_valid(const char *map_path)
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
}

void fill(char **tab, t_point size, int x, int y, char target, int *collected, int *exit_reached)
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

int flood_fill_check(char **tab, t_point size, t_point begin, int total_collectibles)
{
    int collected = 0;
    int exit_reached = 0;
    char target = tab[begin.y][begin.x];

    if (target == '1')
        return (0);

    fill(tab, size, begin.x, begin.y, target, &collected, &exit_reached);

    return (collected == total_collectibles && exit_reached);
}


