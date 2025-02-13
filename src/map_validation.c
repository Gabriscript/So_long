/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:05 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 10:40:48 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
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
		|| (map[y][x] == '1' || map[y][x] == 'F'))
		return ;
	if (map[y][x] == 'C')
		game->collected++;
	if (map[y][x] == 'E')
	{
		game->exit_reached = 1;
		game->exit_y = y;
		game->exit_x = x;
	}
	map[y][x] = 'F';
	fill(game, map, x + 1, y);
	fill(game, map, x - 1, y);
	fill(game, map, x, y + 1);
	fill(game, map, x, y - 1);
}

static int	flood_fill_check(t_game *game)
{
	bool	success;
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		return (false);
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
	{
		ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
		return (false);
	}
	if (!walls(game))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
		return (false);
	}
	if (!has_all_components(game))
	{
		ft_putstr_fd("Error\nInvalid map components (P, C, E).\n", 2);
		return (false);
	}
	if (!flood_fill_check(game))
	{
		ft_putstr_fd("Error\nInvalid path.\n", 2);
		return (false);
	}
	return (true);
}
