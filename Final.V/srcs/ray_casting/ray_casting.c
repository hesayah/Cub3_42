/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:36:31 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/09 17:01:00 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	init_casting(int x, t_data *data)
{
	data->cast.wall = 0;
	data->cast.start = 0;
	data->cast.end = 0;
	data->cast.side = 0;
	data->cast.hit = 0;
	data->cast.mapx = (int)(data->cam.posx);
	data->cast.mapy = (int)(data->cam.posy);
	data->cam.camera_x = (2 * x / (double)(data->w_w)) - 1;
	data->cast.ray_x = (data->cam.dir_x + data->cam.plane_x
	* data->cam.camera_x);
	data->cast.ray_y = (data->cam.dir_y + data->cam.plane_y
	* data->cam.camera_x);
	data->cast.d_ray_x = fabs(1 / data->cast.ray_x);
	data->cast.d_ray_y = fabs(1 / data->cast.ray_y);
}

static	void	init_dda(t_data *data)
{
	if (data->cast.ray_x < 0)
	{
		data->cast.stepx = -1;
		data->cast.side_dist_x = (data->cam.posx - data->cast.mapx)
		* data->cast.d_ray_x;
	}
	else
	{
		data->cast.stepx = 1;
		data->cast.side_dist_x = (data->cast.mapx + 1 - data->cam.posx)
		* data->cast.d_ray_x;
	}
	if (data->cast.ray_y < 0)
	{
		data->cast.stepy = -1;
		data->cast.side_dist_y = (data->cam.posy - data->cast.mapy)
		* data->cast.d_ray_y;
	}
	else
	{
		data->cast.stepy = 1;
		data->cast.side_dist_y = (data->cast.mapy + 1 - data->cam.posy)
		* data->cast.d_ray_y;
	}
}

static	void	play_casting(t_data *data)
{
	while (data->cast.hit == 0)
	{
		if (data->cast.side_dist_x < data->cast.side_dist_y)
		{
			data->cast.side_dist_x += data->cast.d_ray_x;
			data->cast.mapx += data->cast.stepx;
			data->cast.side = 0;
		}
		else
		{
			data->cast.side_dist_y += data->cast.d_ray_y;
			data->cast.mapy += data->cast.stepy;
			data->cast.side = 1;
		}
		if (data->maps[(int)data->cast.mapy][(int)data->cast.mapx] == '2')
			data->srt.hit = 1;
		if (data->maps[(int)data->cast.mapy][(int)data->cast.mapx] == '1')
			data->cast.hit = 1;
	}
}

static	void	engine_casting(int x, t_data *data)
{
	init_dda(data);
	play_casting(data);
	if (data->cast.side == 0)
		data->cast.dist_ray = (data->cast.mapx - data->cam.posx
		+ (1 - data->cast.stepx) / 2) / data->cast.ray_x;
	else
		data->cast.dist_ray = (data->cast.mapy - data->cam.posy
		+ (1 - data->cast.stepy) / 2) / data->cast.ray_y;
	data->cast.wall = data->w_h / data->cast.dist_ray;
	data->cast.start = (-data->cast.wall / 2 + data->w_h / 2);
	if (data->cast.start < 0)
		data->cast.start = 0;
	data->cast.end = (data->cast.wall / 2 + data->w_h / 2);
	if (data->cast.end >= data->w_h)
		data->cast.end = data->w_h - 1;
}

void			ray_casting(t_data *data)
{
	int			x;
	double		buff[data->w_w];

	x = 0;
	data->srt.hit = 0;
	while (x < data->w_w)
	{
		init_casting(x, data);
		engine_casting(x, data);
		if (data->cast.side == 0)
		{
			if (data->cast.mapx - data->cam.posx > 0)
				draw_c_wall(x, data->tex.tex_ea, buff, data);
			else
				draw_c_wall(x, data->tex.tex_we, buff, data);
		}
		else
		{
			if (data->cast.mapy - data->cam.posy > 0)
				draw_c_wall(x, data->tex.tex_so, buff, data);
			else
				draw_c_wall(x, data->tex.tex_no, buff, data);
		}
		buff[x] = data->cast.dist_ray;
	}
	buff[x] = '\0';
	x++;
}
