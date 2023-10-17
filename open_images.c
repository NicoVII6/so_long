/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:13:18 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/14 15:13:18 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

// REVOIR CES STRUCTURES POUR LA SYNTAXE

static void		open_player_image(t_game *game)
{
	game->player.idle_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/leonardo.xpm", &game->img_size.x, &game->img_size.y);
	game->player.curr_img = game->player.action_img; // ???
}

static void		open_collectable_image(t_game *game)
{
	game->collects_img.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/pizza.xpm", &game->img_size.x, &game->img_size.y);
	game->collects_img.curr_img = gaMe->collects_imgs.img_img_1;
}

static void		open_exit_image(t_game *game)
{
	game->exit_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit.xpm", &game->img_size.x, &game->img_size.y);
}

/* fill the map with one unique image for each block of the wall */
static void		open_wall_image(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/brick-wall.xpm",
			&game->img_size.x, &game->img_size.y);
}

/* Opens with the mlx all images for the game */
void	open_images(t_game *game)
{
	open_wall_image(game);
	open_player_image(game);
	open_collectable_image(game);
	open_exit_image(game);
}