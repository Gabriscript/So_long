/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:44:17 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 18:28:50 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			return (false);
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
			x = 0;
			while (x < game->width)
			{
				if (game->map[y][x] != '1')
					return (false);
				x++;
			}
		}
		else if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

static bool	letter_checker(t_game *game, int y, int x)
{
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
			else if (game->map[y][x] != '1' && game->map[y][x] != '0'
					&& game->map[y][x] != '\n')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	has_all_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	game->plyr_count = 0;
	game->coin_count = 0;
	game->exit_count = 0;
	if (!letter_checker(game, y, x)
		|| game->plyr_count != 1 || game->coin_count < 1
		|| game->exit_count != 1)
		return (false);
	return (true);
}

int	check_game(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid argument number\n", 2);
		return (0);
	}
	if (!is_ber(argv[1]))
	{
		ft_putstr_fd("Error\nChoose a .ber extension\n", 2);
		return (0);
	}
	initialization(game);
	if (!read_map(game, argv[1]) || !validate_map(game))
	{
		free_map(game);
		return (0);
	}
	if (game->width * TILE > SCREEN_WIDTH
		|| game->height * TILE > SCREEN_HEIGHT)
	{
		ft_putstr_fd("Error\nMap too big!\n", 2);
		free_map(game);
		return (0);
	}
	return (1);
}
