#include "./minilibx/mlx.h"
#include "lib/libft.h"
#include <math.h>

typedef struct	s_game {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	oldplanex;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	olddirx;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		drawstart;
	int		drawend;
	int		lineheight;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		texwidth;
	int		texheight;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	double	*sx;
	double	*sy;
	double	*zbuffer;
	double	*spritedistance;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		vmovescreen;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
	int		d;
}				t_game;

typedef struct	s_sides {
	char 	*north;
	char	*west;
	char	*east;
	char	*south;
}				t_sides;

typedef struct	s_color {
	unsigned int	rf;
	unsigned int	gf;
	unsigned int	bf;
	unsigned int	rc;
	unsigned int	gc;
	unsigned int	bc;
	unsigned int	clrf;
	unsigned int	clrc;
	unsigned int 	chc;
	unsigned int	chf;
}				t_color;


typedef struct  s_data {
        void    *mlx;
        void    *mlx_win;
        void    *img;
        void   *data;
        int     bpp;
        int     line_length;
        int     endian;
    }           t_img;

typedef	struct		s_win {
	int				pc_width;
	int				pc_height;
	int 			width;
	int 			height;
}					t_win;

typedef	struct		s_file {
	t_sides			sides;
	t_color			color;
	t_win			win;
	t_list			*first;
	t_game			game;
	t_img			img;
	t_img			texn;
	t_img			texe;
	t_img			texw;
	t_img			texs;
	t_img			sprites;
	int				spritesum;
	int				ioooo;
	unsigned int	clr;
	char			*sprite;
	char			**map;
	int				fd;
	char			*line;
	int				stop_map;
	int				stop_gamer;
}					t_file;

int		pars(t_file *file);
void	cub3d(t_file *file);
void	maptrace(t_file *file);
void	engine(t_file *file);
void	onlymap(t_file *file);
void	enginesecond(t_file *file);
void	new_slide(t_file *file);
int		keys(int key, t_file *file);
int		wasd(int key, t_file *file);
void	turn(int key, t_file *file);
void	draw(t_file *file);
void	draw_sprite(t_file *file);
void	sprite_sort(t_file *file);
void	makeside(t_file *file);
void 	get_color(t_file *file);
void	res_error(char **win);
void	look_for_map(t_file *file);
int		flood_fill(t_file *file);
void	lets_free(char **str);