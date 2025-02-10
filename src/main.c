
#include "so_long.h"




//  cc main.c libmlx42.a -ldl -lglfw -pthread -lm*/

 
int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("Error\nUso corretto: ./so_long <mappa.ber>\n");
        return EXIT_FAILURE;
    }

    initialization(&game);

    if (!is_ber(argv[1]))
    {
        ft_printf("Error\nIl file non ha estensione .ber\n");
        return EXIT_FAILURE;
    }

    if (!read_map(&game, argv[1]))
    {
        ft_printf("Error\nErrore nel caricamento della mappa.\n");
        return EXIT_FAILURE;
    }

    if (!validate_map(&game))
    {
        free_map(&game);
        return EXIT_FAILURE;
    }

    game.mlx = mlx_init(800, 600, "so_long", true);
    if (!game.mlx)
    {
        ft_printf("Error\nMLX initialization failed\n");
        free_map(&game);
        return EXIT_FAILURE;
    }

    game.images = load_images(&game);
    if (!game.images)
    {
        ft_printf("Error\nImage loading failed\n");
        free_map(&game);
        mlx_terminate(game.mlx);
        return EXIT_FAILURE;
    }

    render_map(&game);
    render_player(&game);

    mlx_key_hook(game.mlx, input, &game);
    mlx_loop(game.mlx);

    free_map(&game);
    free_images(game.images, game.mlx);
    mlx_terminate(game.mlx);

    return EXIT_SUCCESS;
}




  





