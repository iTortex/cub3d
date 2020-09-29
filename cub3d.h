/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:48:28 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 21:35:29 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_game
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			oldplanex;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			olddirx;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				drawstart;
	int				drawend;
	int				lineheight;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				texwidth;
	int				texheight;
	int				texnum;
	double			wallx;
	int				texx;
	double			step;
	double			texpos;
	int				texy;
	double			*sx;
	double			*sy;
	double			*zbuffer;
	double			*spritedistance;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				vmovescreen;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				d;
}					t_game;

typedef struct		s_sides
{
	char			*north;
	char			*west;
	char			*east;
	char			*south;
}					t_sides;

typedef struct		s_color
{
	unsigned int	rf;
	unsigned int	gf;
	unsigned int	bf;
	unsigned int	rc;
	unsigned int	gc;
	unsigned int	bc;
	int				clrf;
	int				clrc;
	unsigned int	chc;
	unsigned int	chf;
}					t_color;

typedef struct		s_img
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	void			*data;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef	struct		s_win
{
	int				pc_width;
	int				pc_height;
	int				width;
	int				height;
}					t_win;

typedef	struct		s_file {
	t_sides			sides;
	t_color			color;
	t_win			win;
	t_list			*first;
	t_list			*head;
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
	int				check_for_data;
	int				map_size_y;
	int				fd;
	char			*line;
	char			*bmp_check;
	int				stop_map;
	int				stop_gamer;
	int				x_max;
	int				y_max;
	int				f_i;
	int				f_j;
}					t_file;

int					main(int argc, char **argv);
int					pars(t_file *file);
void				cub3d(t_file *file);
void				maptrace(t_file *file);
void				engine(t_file *file);
void				onlymap(t_file *file);
void				enginesecond(t_file *file);
void				new_slide(t_file *file);
int					keys(int key, t_file *file);
int					wasd(int key, t_file *file);
void				turn(int key, t_file *file);
void				draw(t_file *file);
void				draw_sprite(t_file *file);
void				sprite_sort(t_file *file);
void				makeside(t_file *file);
void				get_color(t_file *file);
void				res_error(char **win);
void				look_for_map(t_file *file);
int					flood_fill(t_file *file);
void				lets_free(char **str);
void				make_bmp(t_file *file);
void				textures(t_file *file);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int		my_mlx_pixel_take(t_img *data, int x, int y);
void				data_error(void);
void				ifsides(t_file *file, int y, int x);

#endif
