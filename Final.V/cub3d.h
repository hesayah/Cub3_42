/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:00:25 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/08 15:03:15 by hesayah          ###   ########.fr       */
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

typedef	struct		s_rgb
{
	int r;
	int g;
	int b;
	unsigned long color;
}					t_rgb;

typedef struct		s_map
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
}					t_map;

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
	/*void			*xpm;
	void			*tex_no;
	void			*tex_so;
	void			*tex_ea;
	void			*tex_we;
	void			*tex_s;
	int				tex_y;
	int				tex_x;
	int				txt_w;
	int				txt_h;*/
	unsigned long	floor;
	unsigned long	ceiling;
	/*double			step;
	double			tex_p;
	double			wallx;*/
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
    char 			**tab;
	char			**maps;
    t_tex           tex;
	t_rgb			rgb;
	t_map			map;
	t_cam			cam;

    
}               t_data;

int		loop_hook(t_data *data);
int		close_window(t_data *data);
int	    brain(int argc, char **argv, t_data *data);
void	init_data(t_data *data);
int		pars_brain(char *file, t_data *data);
int     pars_value_line(t_data *data);
int     c_in_str(char c, char *s2);
int		get_res(char *str, t_data *data);
int		scan_id(char *str, t_data *data);
int		get_path_tex(int index, char *str, t_data *data);
unsigned long ft_rgb(int r, int g, int b);
int		ft_get_map(t_data *data, int index);
void    ft_debug(t_data *data);
void    code_err(int code);
int     exit_error(int code, t_data *data);



#endif