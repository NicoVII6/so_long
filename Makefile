NAME = so_long

SRCS = main.c map_checkers.c game_init.c \
		draw_map.c draw_wall.c map_reader.c \
		open_images.c open_panel.c player_move.c \
		restart_game.c player_end.c tilemap_building.c \
		input_management.c end_program.c utils_libf.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I./ -I./libft/
MLX = -Imlx ./mlx/libmlx.a -framework OpenGL -framework AppKit

LIBS = ./libft/libft.a

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
		@make -C libft
		@make -C mlx
		$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(MLX) $(LIBS) -o $(NAME)
		$(info CREATED $(NAME))

%.o : %.C
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
		$(info CREATED $@)

clean :
		@make clean -C libft/
		@make clean -C mxl/
		$(RM) $(OBJS)
		$(info DELETED objects files)

fclean : clean
		@make fclean -C libft/
		$(RM) $(NAME)
		$(info DELETED $(NAME))

re :
	$(make) fclean
	$(make) all

.PHONY : clean fclean re info-