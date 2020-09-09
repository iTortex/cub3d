SRC = main.c pars.c cub3d.c maptrace.c engine.c onlymap.c enginesecond.c new_slide.c
OBJ = $(SRC:.c=.o)
NAME = cub3d
CC = clang
FLAG = -Wall -Wextra -Werror
MLX = -L./minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -lm -Llib -lft

all: $(NAME)

libft:
	cd lib && make && make bonus && cp libft.a ../

$(NAME): libft
	$(CC) -g $(FLAG) $(SRC) $(MLX) $(LIBFT)
	cd minilibx_mms_20200219 && cp libmlx.dylib ../
	cd lib && make

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Imlx -Ilib -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean	
	/bin/rm -f libmlx.dylib a.out
	cd lib && make fclean

re: fclean all

.PHONY: all clean fclean re bonus