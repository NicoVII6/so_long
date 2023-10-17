/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:40:31 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/15 11:40:31 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

/* Returns a t_color struct */
t_color		new_color(int r, int g, int b, int a)
{
	t_color		color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

/* set all pixels in 'panel' to 'color' */
void	color_panel(t_panel *panel, t_color color)
{
	int		x;
	int		y;

	// get pixel data of the panel image and its format,
	// 'bpp' equal to bits per pixel
	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp,
				&panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		// sets the color values of the current pixel
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
			x++;
		}
		y++;
	}
}

/* Returns pointer of a colored image with the same size as the window 
 * it initialize a t_panel structure and set its properties which are
 * the image pointer and the size, and fills the image with the specified
 * color using the 'color_panel' function */
void	*new_panel(t_game *game, t_color color)
{
	t_panel		panel;

	panel.pointer = mlx_new_image(game->mlx, game->window_size.x,
							game->window_size.y);
	panel.size.x = game->window_size.x;
	panel.size.y = game->window_size.y;
	color_panel(&panel, color);
	return (panel.pointer);
}