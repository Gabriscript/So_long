/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 10:01:33 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_game(argc, argv, &game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game.mlx = mlx_init(game.width * TILE, game.height * TILE, "so_long", true);
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nMLX init failed\n", 2);
		free_map(&game);
		return (EXIT_FAILURE);
	}
	game.imgs = load_images(&game);
	if (!game.imgs)
	{
		ft_putstr_fd("Error\nImage load failed\n", 2);
		free_map(&game);
		mlx_terminate(game.mlx);
		return (EXIT_FAILURE);
	}
	render_map(&game);
	render_player(&game);
	mlx_key_hook(game.mlx, input, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	free_images(game.imgs, game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
    //mlx_get_monitor_size
}
