#include <mlx.h>
#include "lib/libft.h"

typedef struct	s_sides {
	char 	*north;
	char	*west;
	char	*east;
	char	*south;
}				t_sides;

typedef struct	s_color {
	unsigned int r;
	unsigned int g;
	unsigned int b;
}				t_color;

typedef struct  s_data {
        void    *mlx;
        void    *mlx_win;
        void    *img;
        void   *data;
        int     bpp;
        int     line_length;
        int     endian;
    }           t_data;

typedef	struct		s_win {
	unsigned int 	width;
	unsigned int 	lenght;
}					t_win;

typedef	struct		s_file {
	t_sides			sides;
	t_color			color;
	t_win			win;
	char			*sprite;
	char			**map;
	char			*line;
}					t_file;

void	pars(t_file *file);
