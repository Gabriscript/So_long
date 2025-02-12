/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/12 18:28:54 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_game(argc, argv, &game))
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
}
