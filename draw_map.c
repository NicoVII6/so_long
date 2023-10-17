/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:48:01 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/15 10:48:01 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

void	draw_wall(t_tile tile, t_game game, t_vector pos);

/* draw the corresponding image of the tile type 
 * checker le nom des images */
static void		draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(game.mlx, game.window, game.exit_img,
			pos.x, pos.y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window, game.pizza_img,
			pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window, game.player,
			pos.x, pos.y);
}

/* writes the number of moves on the window 
 * A FAIRE */
static void		write_moves(t_game game);

/* puts the tile map on the window 
 * A REVOIR */
void	map_drawing(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
	write_moves(game);
}