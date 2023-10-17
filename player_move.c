/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:10:11 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/15 11:10:11 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

/* if the player is moving somewhere different from EXIT (and walls) 
 * we set the player previous location to empty and we set the current
 * tile (position) by the player */
void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	move_to_collectable(t_game *game, t_tile *tile)
{
	tile->type = EMPTY; // set the collect tile by the empty one
	game->collects--; // decrement collect counter
	// what about the player move !!
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0); // ???
	remove_player(game); 
	game->collects = -1; // we set the collect counter to -1
}