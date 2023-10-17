#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx/mlx.h>

#define ESC 53
#define KEY_UP 13
#define KEY_DOWN 1
#define KEY_LEFT 0
#define KEY_RIGHT 2 
#define RESET 15 

typedef struct	s_mapchecker
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}		t_mapchecker;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}		t_tiletype;

typedef enum e_bool
{
	TRUE = 1;
	FALSE = 0;
}		t_bool;

typedef struct s_vector
{
	int		x;
	int		y;
}		t_vector;

/* struct to create a colored image (panel) with the same size as the game window */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}		t_panel;

/* An image that covers the whole window
 * 'bits_per_pixel' tells us the number of bits needed to represent a pixel color
 * 'size_line' tells us how many pixels are in each line of the image. Because pixels
 * of the image are not stored in a 2D array but all in a row in a single array.
 * So each pixel is represented by 4 chars, allowing us to get access to every pixel
 * on the image with the formula : X_position * 4 + Y_position 
 * 'endian' can be either 0 or 1, depending on the system and it defines how colors are
 * stored. here the 1st character is blue, then green, then red and finally the alpha or
 * transparency of the pixel. each value of each color goes from 0 to 255*/
typedef struct	s_image
{
	void		*pointer;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_color
{
	int		r; // red
	int		g; // green
	int		b; // blue
	int		a; // alpha-transparency
}		t_color;

/* 'type' can be Empty, Wall, Collectable, Player, Exit
    'og_type' for original type, used to reset the game
	'position' defines the pixel coordinates of the tile to be drawn in the window
	all our sprites are 64x64 pixels, so the position of each tile is its coordinates
	in the table multiply by 64
	Finally we have pointers to all the adjacent tile in every direction */
typedef struct	s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

/* with a pointer to the tile where the player is currently on the map 
 * So if the player moves, for example to the right. the program go to its tile,
 * which has a pointer to the one on the right and check :
 * -> if it's a wall, player just don't move so we don't add anything to the moves counter
 * -> if it's an empty space, the program set the player to the new place, so the new
 * 	tile as player type and the old one as empty 
 * -> if it's a collectable, it sets it as empty and reduce by one the collectables counter
 * -> if it's the exit and collectables counter are equal to 0, it kill the player (set his tile
 *  to NULL) and puts collectables counter to -1 so the render function (clears the window and
 *  loop through each tile drawing the image that corresponds to its type) */
typedef struct s_player
{
	t_tile		*tile;
	void		*curr_img;
	//int			framecount;
}	t_player;


// VERIFIER SI IL NE MANQUE PAS D'ELEMENT DS STRUCT
typedef struct s_game
{
	void		*mlx;			// pointer to the mlx
	void		*window;		// pointer to the window
	t_vector	window_size;
	t_tile		**tilemap;		// 2D tile table
	t_player	player;			// struct with all the data about the player
	
	int			og_collects;	// original collectable that can be reset
	int			collects;		// current value of collectable, reduce by one each time we pick one
	int			moves;			// moves counter, add one for each move

	t_vector	img_size;
	void		*door_img;		// image for the exit
}	t_game;


#endif