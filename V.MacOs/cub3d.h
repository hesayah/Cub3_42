/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:00:25 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:39:07 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include "libs/mlx/mlx.h"
#include "libs/libft/libft.h"
#include "libs/gnl/get_next_line.h"

typedef struct		s_cast
{
	int				mapx;
	int				mapy;
	double			ray_x;
	double			ray_y;
	double			d_ray_x;
	double			d_ray_y;
	int				stepx;
	int				stepy;
	double			side_dist_x;
	double			side_dist_y;
	double			dist_ray;
	double			wall;
	int				start;
	int				end;
	int				side;
	int				hit;
	double			*buff;
} 					t_cast;

typedef	struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;


typedef struct		s_srt
{
	int				hit;
	double			sprite;
	double			sprite_x;
	double			sprite_y;
	double			m_inv;
	double			tr_x;
	double			tr_y;
	int				srt_pos_x;
	int				srt_h;
	int				draw_sy;
	int				draw_ey;
	int				srt_w;
	int				draw_sx;
	int				draw_ex;
	int				srt_x;
	int				srt_y;
	int				pixel;
	unsigned long	color;
}					t_srt;

typedef	struct		s_rgb
{
	int r;
	int g;
	int b;
	unsigned long color;
}					t_rgb;

typedef struct		s_maps
{	
	int				map_w;
	int				map_h;	
	int				m_x;
	int				m_y;	
	int				map_x;
	int				map_y;
	int				spown;
	int				n_srt;
	double			r_map;
}					t_maps;

typedef struct		s_cam
{
	double			posx;
	double			posy;
	double			camera_x;
	double			dir_eye;
	double			speed;
	double			rot_speed;
	double			old_plane_x;
	double			plane_x;
	double			plane_y;
	double			old_dir_x;
	double			dir_x;
	double			dir_y;
}					t_cam;



typedef struct		s_tex
{
	char 			*r_path[5];
	int 			bits_per_pixel;
	int 			line_length;
	int 			endian;
	int				img_width;
	int				img_height;
	void			*xpm;
	void			*tex[5];
	int				tex_y;
	int				tex_x;
	int				txt_w;
	int				txt_h;
	unsigned long	floor;
	unsigned long	ceiling;
	double			step;
	double			tex_p;
	double			wallx;
}					t_tex;

typedef struct  s_data
{
  	void 			*mlx;
	void 			*win;
	void 			*img;
	char 			*addr;
	int 			bits_per_pixel;
	int 			line_length;
	int 			endian;
	int 			w_w;
	int 			w_h;
	int				err;
    char 			**tab;
	char			**map;
    t_tex           tex;
	t_rgb			rgb;
	t_maps			maps;
	t_cam			cam;
	t_srt			srt;
	t_sprite		*sprite;
	t_cast			cast;

    
}               t_data;

void	loop_hook(t_data *data);
int		close_window(t_data *data);
int		ft_check_arg(int argc, char *str);
int	    brain(int argc, char **argv, t_data *data);
void	init_data(t_data *data);
void	pars_brain(char *file, t_data *data);
int  	 pars_value_line(t_data *data);
int     c_in_str(char c, char *s2);
void	get_res(char *str, t_data *data);
int		scan_id(char *str, t_data *data);
void	get_path_tex(int index, char *str, t_data *data);
unsigned long ft_rgb(int r, int g, int b);
void	ft_get_map(int index, t_data *data);
void	init_map_and_cam(t_data *data);
int		get_first_player_pos(t_data *data);
int 	pars_sprite(t_data *data);
int		load_xpm(t_data *data);
int		action_key(int keycode, t_data *data);
int		render_next_frame(t_data *data);
void	ray_casting(double *buff, t_data *data);
void    my_mlx_pixel_put(int x, int y, int color, t_data *data);
void	draw_c_wall(int x, int *txt, t_data *data);
void 	draw_map(t_data *data);
void 	draw_player(t_data *data);
void	init_sprite(t_data *data);
void 	brain_sprite(int *srt, double *buff, t_data *data);
void	init_data_sprite(t_data *data);
void	draw_sprite(int *srt, double *buff, t_data *data);
void    ft_debug(t_data *data);
void	save(t_data *data);
void	save_frame(t_data *data);
void    code_err(int code);
void    exit_error(int code, t_data *data);
int 	clean_up(int code, t_data *data);



#endif