/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:40:21 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/14 11:40:21 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	move_to_collectable(t_game *game, t_tile *tile);

/* move the player to a tile doing what is needed based on the tile type */
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		move_to_collectable(game, tile);
	else if (tile->type == EXIT && game->collects == 0)
		move_to_exit(game, tile);
	else
		return (FALSE);
	return (TRUE);
}

/* function called each time a key is pressed by the user */
int		user_input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
		//return (write(STDOUT_FILENO, "The key is not valid, try again\n", 33));
	if (moved)
		ft_printf("Moves : %d\n", ++game->moves); //linker ft_printf
	return (1);
}
