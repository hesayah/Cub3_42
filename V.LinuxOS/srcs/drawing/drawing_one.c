/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:19:20 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:13:37 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void            my_mlx_pixel_put(int x, int y, int color, t_data *data)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned long ft_rgb(int r, int g, int b)
{   
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ((int)(-1));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static	void	texture_calc(int x, t_data *data)
{	
	if (data->cast.side == 0)
		data->tex.wallx = data->cam.posy + data->cast.dist_ray
		* data->cast.ray_y;
	else
		data->tex.wallx = data->cam.posx + data->cast.dist_ray
		* data->cast.ray_x;
	data->tex.wallx -= (int)data->tex.wallx;
	data->tex.tex_x = (int)(data->tex.wallx * 1024);
   if (data->cast.side == 0 && data->cast.ray_x > 0)
		data->tex.tex_x = 1024 - data->tex.tex_x - 1;
    if (data->cast.side == 1 && data->cast.ray_y < 0)
		data->tex.tex_x = 1024 - data->tex.tex_x - 1;
	data->tex.step = 1024 / (data->cast.wall + 1);
	data->tex.tex_p = (data->cast.start - data->w_h / 2
	+ data->cast.wall / 2) * data->tex.step;
}

void	        draw_c_wall(int x, int *txt, t_data *data)
{
	int y;
	y = 0;
	texture_calc(x,data);
	while (y < data->w_h)
	{
		if (y < data->cast.start)
			my_mlx_pixel_put(x, y, data->tex.ceiling, data);
		else if (y > data->cast.start && y < data->cast.end)
		{
			data->tex.tex_p += data->tex.step;
			data->tex.tex_y = (int)(data->tex.tex_p) % 1024;
			my_mlx_pixel_put(x, y,  txt[(1024 * data->tex.tex_y) - data->tex.tex_x], data);
		}
		else
			my_mlx_pixel_put(x, y, data->tex.floor, data);
		y++; 
	}
}