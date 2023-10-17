/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:03:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/08 13:03:04 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "path for the map"

void	open_images(t_game *game);
t_tile	**generate_map(char **map, t_game *game);

// creates a map according to the first file of argv
t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile 	**tile_map;

	//check si fichier recu valide
	if(!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map(argv[1]);//initialise variable si fichier bon 
	if (!map)
		return (NULL);
	if (valid_map(map) != TRUE)
	{
		ft_free_array(map);
		return (NULL);
	}
	tile_map = generate_tilemap(map, game);
	ft_free(map);
	if (!tile_map)
		return (NULL);
	return (tile_map);
}

// A Revoir et retravailler
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
		game->window_size.x + IMG_SIZE / 2, game->window_size.y, "so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	// faire une config de color est suffisant
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

/* initialize the game structure */
t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	game_init(game);
	return (TRUE);
}