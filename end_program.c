/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:37 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/14 11:33:37 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->map;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free(tilemap);
}

int		end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap == NULL;
	exit (0);
}