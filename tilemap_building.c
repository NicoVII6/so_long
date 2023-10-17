/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_building.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:41:47 by ndecotti          #+#    #+#             */
/*   Updated: 2023/10/13 15:41:47 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"

/* Allocates memory to save a tilemap with the same size as the map 
 * retourne un pointeur de pointeur sur la tilemap */
t_tile	**memory_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	// malloc chaque line du tableau representant la map
	tilemap = malloc(sizeof(t_tile *) * (ft_array_linecount(map) + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		// malloc des elements qui se trouvent sur chaque ligne de la map
		// etant donne que map doit etre rectangulaire, chaque ligne same taille
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		// si malloc d'une des lignes echoue, on free toutes les lignes malloc auparavant
		// et on retourne NULL
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[--i]);
			free(tilemap); 
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

/* takes a character as parameter and returns the tiletype that corresponds to 'definer
 * used to map character specific tile types such as 1 for WALL...*/
t_tiletype		define_tiletype(char definer)
{
	if (definer == '1')
		return (WALL);
	else if (definer == 'C')
		return (COLLECTABLE);
	else if (definer == 'P')
		retunr (PLAYER);
	else if (definer == 'E')
		return (EXIT);
	else
		return (EMPTY);
}

/* sets up a 't_tile' structure in the 'tilemap' at position (x,y) with the data
 * sets the 'og_type' to the current type and initialize position based on 'x'
 * and 'y', and establishes the neighboring tile pointers.
 * Important for Tracking the state of each tile and determining neighbor relationships */
void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

/* add info to the game struct if needeed */
void	set_game_var(t_tile *tile, t_game *game, char c)
{
	if (tile->type == PLAYER)
		game->player.tile = tile; // actualise coordonnees player ??
	else if (tile->type == COLLECTABLE)
		game->collects++; // increments collects counter
}
/* functions which constructs the game's tilemap based on the 'map' and
/* and the game structure. It maps the characters in the map with the t_tiletype
/* setting up each tile using 'setup_tile' function and calls 'set_game_var'
/* to update the game structure
/* Returns a pointer to t_tile table filled according to 'map', each line ends 
 * in a tile of type 0, and columns ends in a NULL pointer */
t_tile	**make_map(char **map, t_game *game)
{
	t_tile		**tilemap;
	int			x;
	int			y;

	tilemap = memory_tilemap(map);
	if (!tilemap)
		return (write(STDERR_FILENO, "Error during malloc process\n", 29));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type =define_tiletype(map[y][x]);
			setup_tile(tilemap, x, y);
			set_game_var(&tilemap[y][x], game, map[y][x]);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] == NULL; // on ferme derniere colonne ac NULL pointer
	game->window_size.x = x * IMG_SIZE;
	game->window_size.y = y * IMG_SIZE;
	// calculates window size based of the map size in the game struc
	return (tilemap);
}