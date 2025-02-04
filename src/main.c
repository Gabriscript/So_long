
#include "so_long.h"




//  cc main.c libmlx42.a -ldl -lglfw -pthread -lm*/

 int main(void) {
    t_game game;
    int width = 0, height = 0;

    game.mlx = mlx_init(800, 600, "so_long", true);
    if (!game.mlx) {
        ft_printf("Error: MLX initialization failed\n");
        return EXIT_FAILURE;
    }
    game.images = load_images(game.mlx);
    if (!game.images) {
        ft_printf("Error: Image loading failed\n");
        return EXIT_FAILURE;
    }
    game.map = read_map("./maps/map.ber", &width, &height);
    if (!game.map) {
        ft_printf("Error reading map\n");
        return EXIT_FAILURE;
    }
    game.width = width;
    game.height = height;
    render_map(game.mlx, game.map, width, height, game.images);
    mlx_loop_hook(game.mlx, input, &game);
    mlx_loop(game.mlx);
    free_map(game.map, height);
    free(game.images);
    mlx_terminate(game.mlx);
    return EXIT_SUCCESS;
}
int main(int argc, char **argv)
{
    t_game game;
    int width = 0, height = 0;

    if (argc != 2)
    {
        ft_printf("Error\nUso corretto: ./so_long <mappa.ber>\n");
        return EXIT_FAILURE;
    }

    if (!is_ber(argv[1])) // Controllo se il file ha estensione .ber
    {
        ft_printf("Error\nIl file non ha estensione .ber\n");
        return EXIT_FAILURE;
    }

    // Legge la mappa
    game.map = read_map(argv[1], &width, &height);
    if (!game.map)
    {
        ft_printf("Error\nErrore nel caricamento della mappa.\n");
        return EXIT_FAILURE;
    }

    // ✅ Controllo se la mappa è valida
    if (!validate_map(game.map, width, height))
    {
        free_map(game.map, height);
        return EXIT_FAILURE;
    }

    // ✅ Se la mappa è valida, avvia il gioco normalmente
    game.width = width;
    game.height = height;

    game.mlx = mlx_init(800, 600, "so_long", true);
    if (!game.mlx)
    {
        ft_printf("Error\nMLX initialization failed\n");
        free_map(game.map, height);
        return EXIT_FAILURE;
    }

    game.images = load_images(game.mlx);
    if (!game.images)
    {
        ft_printf("Error\nImage loading failed\n");
        free_map(game.map, height);
        return EXIT_FAILURE;
    }

    render_map(game.mlx, game.map, width, height, game.images);
    mlx_loop_hook(game.mlx, input, &game);
    mlx_loop(game.mlx);

    // Pulizia memoria
    free_map(game.map, height);
    free(game.images);
    mlx_terminate(game.mlx);

    return EXIT_SUCCESS;
}


  





