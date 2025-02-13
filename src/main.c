/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:01:33 by ggargani          #+#    #+#             */
/*   Updated: 2025/02/13 14:39:51 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_game(argc, argv, &game))
		return (EXIT_FAILURE);
	if (!init_game(&game))
		return (EXIT_FAILURE);
	render_map(&game);
	render_player(&game);
	mlx_key_hook(game.mlx, input, &game);
	mlx_loop(game.mlx);
	free_images(game.imgs, game.mlx);
	free_map(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
