/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:14:38 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/08 13:14:38 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"


// Returns True if the file is valid
int		valid_file(int argc, char *file)
{
	if (argc == 1)
		return (write(STDERR_FILENO, "Error\n no arguments\n", 21));
	if (argc > 2)
		return (write(STDERR_FILENO, "only the first arg will be used\n", 33)); // can compile cause it s just a warning
	if (!ft_type_comp(file, ".ber"))
		return (write(STDERR_FILENO, "Error\n map should be .ber\n", 27));
	return (1);		
}

/* returns TRUE if 'c' is a valid map character */
int		valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (TRUE);
	else
		return (FALSE);
}

// turns bool to TRUE when c is equal to checker
// returns FALSE if bool is already TRUE, meaning more than once
int		valid_unique_char(char c, char checker, t_bool *bool)
{
	if (c == checker && *bool == FALSE)
		*bool == TRUE;
	else if (c == checker && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

// check for the border of the map if all are made of 1
// if not, return FALSE
int		valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0 || point.y == size.y - 1
		|| point.x == size.x - 1)
		if (c != '1')
			return (FALSE);
	return (TRUE);
}

/* this function refers to the struct we have created in the .h
/* data is a struct that uses the struc model from .h
/* this struct initialize the data with default values and returns the data variables */
static	t_mapchecker	init_data(char **map)
{
	t_mapChecker	data;

	data.size.x = ft_strlen(map[0]); // taking the length of the first row is enough, cause it contains all the columns of the map
	data.size.y = //fonction qui compte le nb de lignes de map
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE; // b_name because we are using boolean flags
	data.point.y = 0;
	data.point.x = 0; // both indicates that the function has not yet encountered any char in the map
	return (data);
}

/* Check to each tile of the map if it respects the rules 
 * returns TRUE if good, error message if not */
static int	ft_check_map(char **map, t_mapchecker *data)
{
	int		x;
	int		y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (write(STDERR_FILENO, "Error\n invalid map character\n", 30));
	if (!valid_unique_char(map[y][x], 'P', &data->b_player)) // why don't we use this function for exit ??
		return (write(STDERR_FILENO, "Error\n Only one player allows\n", 31));
	if (map[y][x] == 'E')
		data->b_exit = TRUE; //on actualise valeur par defaut a TRUE car bien Un Exit
	if (!valid_border(map[y][x], data->point, data->size))
		return (write(STDERR_FILENO, "Error\n map is not surrounded by walls\n", 39));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

/* function that takes a 2D array of characters and returns TRUE or FALSE
/* indicating whether the map is valid or not
/* to do so, the function uses the 'mapchecker' struct to keep a track of
/* important information
/* it first initializes the 'mapchecker' by calling init_data function
/* and initialize the boolean variable to TRUE
/* then the function loops trough each character in the map array, starting
/* from the top left corner and moving left to right from top to bottom
/* for each character */
int		valid_map(char **map)
{
	t_mapchecker	data;
	t_bool			valid;

	data = init_data(map); // that's here where both data.point.x and data.point.y are initialize to 0
	valid = TRUE;
	while (map[data.point.y])
	{
		//ensure that each row in the map has the same size as the first one
		if (ft_strlen(map[data.point.y] != data.size.x))
		{
			valid = FALSE;
			write(STDERR_FILENO, "Error\n map must be rectangular\n", 32);
		}
		data.point.x = 0; // already is for the first line but need for the next ones
		// this loop goes through each character in the current line, using
		// data.point.x as index and continue until it reachs the end of the line
		// which is when map[data.point.y][data.point.x] returns 0
		while (map[data.point.y][data.point.x])
		{
			//for each character in the line ft_check_map() is called
			// passing map and data pointers
			if (ft_check_map(map, &data) == FALSE)
				valid = FALSE; // what about the message error for this one ?
			(data.point.x)++;
		}
		//when it reach the end of a line, the inner loop continues with the next line
		(data.point.y)++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
	{
		valid = FALSE;
		write(STDERR_FILENO, "Error\n must be one E, one P and at least one C\n", 48);
	}
	return (valid);
}
//check if the map contains only good characters
//check if the player P is unique
//check if the Exit is unique too
//check if there is at least one item to collect
//check if all the border blocks are made of 1
//check if the map is rectangular