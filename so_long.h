#ifndef SO_LONG_H
# define SO_LONG_H

// linker avec so_long_struct, gnl et printf

// map_checkers
int		valid_file(int argc, char *file);
int		valid_char(char c);
int		valid_unique_char(char c, char checker, t_bool *bool);
int		valid_border(char c, t_vector point, t_vector size);
int		valid_map(char **map);

// game init
t_tile	**map_init(int argc, char **argv, t_game *game);
void	game_init(t_game *game);
t_bool	start(t_game *game, int argc, char **argv);

// draw wall
t_bool	draw_corner(t_tile tile, t_game game, t_vector pos);
t_bool	draw_sides(t_tile tile, t_game game, t_vector pos);
void	draw_wall(t_tile tile, t_game game, t_vector pos);

// tilemap_building
t_tile	**memory_tilemap(char **map);
t_tiletype		define_tiletype(char definer);
void	setup_tile(t_tile **tilemap, int x, int y);
void	set_game_var(t_tile *tile, t_game *game, char c);
t_tile	**make_map(char **map, t_game *game);

// open_panel
t_color		new_color(int r, int g, int b, int a);
void	color_panel(t_panel *panel, t_color color);
void	*new_panel(t_game *game, t_color color);

// open images
void	open_images(t_game *game);

// map reader
char	**read_map(char *file);

// draw map
void	map_drawing(t_game game);

// restart game
int	restart(t_game *game);

// utils libft
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd); // !
int		ft_strcmp(const char *s1, const char *s2);
int		ft_type_cmp(const char *str, const char *suffix);
void	ft_free_array(char **arr);
int		ft_array_linecount(char **arr);

// input_management
t_bool	move_to(t_game *game, t_tile *tile);
int		user_input(int key, t_game *game);

// player_move
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_collectable(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);

// player end
void	kill_player(t_game *game, t_vector pos);
void	remove_player(t_game *game);

// end program
void	free_tilemap(t_game *game);
int		end_program;

#endif