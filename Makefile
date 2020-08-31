SRC = main.c pars.c
OBJ = $(SRC:.c=.o)
NAME = cub3d
CC = clang
FLAG = -Wall -Wextra -Werror
MLX = -L./minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -lm -Llib -lft -g

all: $(NAME)

libft:
	cd lib && make && cp libft.a ../

$(NAME): libft
	$(CC) $(FLAG) $(SRC) $(MLX) $(LIBFT)
	cd minilibx_mms_20200219 && cp libmlx.dylib ../
	cd lib && make

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Ilib -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean	
	/bin/rm -f libmlx.dylib a.out
	cd lib && make fclean

re: fclean all

.PHONY: all clean fclean re bonus