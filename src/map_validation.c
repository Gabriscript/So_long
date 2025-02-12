/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:05 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:05 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

bool	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i])
			- (game->map[i][ft_strlen(game->map[i]) - 1] == '\n');
		if (len != game->width)
		{
			ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		if (y == 0 || y == game->height - 1)
		{
			while (x < game->width)
			{
				if (game->map[y][x] != '1')
				{
					ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
					return (false);
				}
				x++;
			}
		}
		else if (game->map[y][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
			return (false);
		}
		y++;
	}
	return (true);
}

bool	component(t_game *game)
{
	int	y;
	int	x;

	game->plyr_count = 0;
	game->coin_count = 0;
	game->exit_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->plyr_x = x;
				game->plyr_y = y;
				game->plyr_count++;
			}
			else if (game->map[y][x] == 'E')
				game->exit_count++;
			else if (game->map[y][x] == 'C')
				game->coin_count++;
			else if (game->map[y][x] != '1' && game->map[i][j] != '0'
					&& game->map[i][j] != '\n')
			{
				ft_putstr_fd("Error\nInvalid character in map.\n", 2);
				return (false);
			}
			x++;
		}
		y++;
	}
	if (game->plyr_count != 1 || game->coin_count < 1 || game->exit_count != 1)
	{
		ft_putstr_fd("Error\nInvalid map components (P, C, E).\n", 2);
		return (false);
	}
	return (true);
}

static void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < heighti)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**copy_map(t_game *game)
{
	char	**copy;// controlla se  devi fare *copy  e non solo copy per il malloc
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[game->height] = NULL;
	return (copy);
}

static void	fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height
        ||	(map[y][x] == '1' || map[y][x] == 'F'))
		return ;
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

static int	flood_fill_check(t_game *game)
{
    int		i;
	bool	success;
	char	**map_copy;

	i = 0;
	map_copy = copy_map(game);
	if (!map_copy)
		return (false);
	while (i < game->height)
	{
		ft_printf("%s\n", map_copy[i]);
		i++;
	}
	game->collected = 0;
	game->exit_reached = 0;
	fill(game, map_copy, game->plyr_x, game->plyr_y);
	success = (game->collected == game->coin_count && game->exit_reached == 1);
	free_map_copy(map_copy, game->height);
	return (success);
}

bool	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		return (false);
	if (!walls(game))
		return (false);
	if (!component(game))
		return (false);
	if (!flood_fill_check(game))
	{
		ft_putstr_fd("Error\nNon esiste un percorso valido nella mappa.\n", 2);
		return (false);
	}
	return (true);
}
