
#include "so_long.h"




//  cc main.c libmlx42.a -ldl -lglfw -pthread -lm*/

int main(void)
{
    t_game game;
    char **map;
    int width = 0, height = 0;

    // Initialize MLX and window
    game.mlx = mlx_init(800, 600, "so_long", true);
    if (!game.mlx)
    {
        ft_printf("Error: MLX initialization failed\n");
        return (EXIT_FAILURE);
    }

    // Allocate memory for images
    game.images = load_images(game.mlx); // Load images before rendering
    if (!game.images)
    {
        ft_printf("Error: Image loading failed\n");
        return (EXIT_FAILURE);
    }

    // Read the map from file
    map = read_map("./maps/map.ber", &width, &height);
    if (!map)
    {
        ft_printf("Error reading map\n");
        return (EXIT_FAILURE);
    }

    // Render the map
    render_map(game.mlx, map, width, height, game.images); // Pass images pointer to render_map

    // Start the MLX event loop
    mlx_loop(game.mlx);
    render_map(game.mlx, map, width, height, game.images);

    input(game.mlx);
    // Free resources
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);

    // Free the images memory
    free(game.images);

    mlx_terminate(game.mlx);

    return (EXIT_SUCCESS);
}
//                   TO DO 

//	 IMPLEMENT PLAYER MOVEMENT
//   RENDER UNDER THE PLAYER AND COIN THE FLOOR
//  POLISHING  THE CODE
//   





