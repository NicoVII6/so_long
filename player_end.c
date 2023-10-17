/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:28:12 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/15 11:28:12 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	mlx_put_image_to_window(game->m;x, game->window, game->red_panel, 0, 0);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}