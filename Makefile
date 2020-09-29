SRCS =  main.c\
		pars.c\
		cub3d.c\
		maptrace.c\
		engine.c\
		onlymap.c\
		new_slide.c\
		wasd.c\
		turn.c\
		draw.c\
		draw_sprite.c\
		sprite_sort.c\
		makeside.c\
		get_color.c\
		res_error.c\
		look_for_map.c\
		flood_fill.c\
		lets_free.c\
		make_bmp.c\
		textures.c\
		my_mlx_pixel_put.c\
		my_mlx_pixel_take.c\
		data_error.c\
		ifsides.c\

OBJS = $(SRCS:.c=.o)
NAME = cub3D
RM = rm -f 
CFLAGS = -O3 -g -Wall -Wextra -Werror -Iinc/ -Imlx/
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft
MLX = libmlx.dylib
LIBFT = ./libft/libft.a
CC = clang

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX) $(LIBFT)
	clang ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
	@cp mlx/$(MLX) .

$(LIBFT):	$(MLX)
	@$(MAKE) -C libft

$(MLX):
	@$(MAKE) -C mlx

clean:
	$(RM) $(OBJS)
	# rm -f ./libft/*.o

fclean: clean	
	$(RM) $(NAME) $(MLX) $(LIBFT) ./mlx/$(MLX)
	
re: fclean $(NAME)

.PHONY: all clean fclean re libft