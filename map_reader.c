/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:53 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/08 21:15:53 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_struct.h"
//#include "../gnl/get_next_line.h"

/* returns how many '\n' are in the file 
/* use open, read and close functions */
static int		file_linecount(char *file)
{
	int		count;
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	count = 1;
	while (1)
	{
		if (read(fd, &c, 1) == 0)
			break ; // si fichier est vide
		if (read(fd, &c, 1) < 0)
			return (-1); // erreur ds la lecture
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

/* Allocates memory for an array of strings
/* with as much strings (rows) as lines in the file 
/* returns a pointer to this 2D array */
static char		**map_rows(char *file)
{
	char	**map;
	int		linecount;

	linecount = file_linecount(file);
	if (linecount <= 0)
		return (write(STDERR_FILENO, "Error\n open or reading file error\n", 35));
	map = malloc(sizeof(char *) * (linecount + 1));
	if (map == NULL)
		return (write(STDERR_FILENO, "Error\n failed to malloc\n", 25));
	return (map);
}

/* takes a pointer to the file as argument and returning a
/* pointer to a 2D array of characters containing the content of the file
/* get_next_line is reading each line from the fd and returning it as
/* a string without the newline char. read_map uses a loop to read all
/* the lines (with gnl) and store them in a 2D array of char */
char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = map_rows(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}