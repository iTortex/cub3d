SRC = main.c pars.c cub3d.c maptrace.c engine.c onlymap.c new_slide.c wasd.c turn.c draw.c draw_sprite.c sprite_sort.c makeside.c get_color.c res_error.c look_for_map.c flood_fill.c lets_free.c
OBJ = $(SRC:.c=.o)
NAME = cub3d
CC = clang
FLAG =  -Wall -Wextra -Werror -g
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -Llib -lft

all: $(NAME)

libft:
	cd lib && make && make bonus && cp libft.a ../

$(NAME): libft
	$(CC) $(FLAG) $(SRC) $(MLX) $(LIBFT)
	# $(CC) -g $(FLAG) $(SRC) $(MLX) $(LIBFT)
	cd minilibx && cp libmlx.dylib ../
	cd lib && make

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Ilib -c $< -o $@
	# $(CC) -g -Wall -Wextra -Werror -Imlx -Ilib -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean	
	/bin/rm -f libmlx.dylib a.out
	cd lib && make fclean

re: fclean all

.PHONY: all clean fclean re bonus