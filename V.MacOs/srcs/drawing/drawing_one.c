/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:19:20 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/26 00:20:06 by hedi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			my_mlx_pixel_put(int x, int y, int color, t_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static	void	texture_calc(int x, int index, t_data *data)
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

void			draw_c_wall(int x, int index, t_data *data)
{
	int y;

	y = 0;
	texture_calc(x, index, data);
	while (y < data->w_h)
	{
		if (y < data->cast.start)
			my_mlx_pixel_put(x, y, data->tex.ceiling, data);
		else if (y > data->cast.start && y <= data->cast.end)
		{
			data->tex.tex_p += data->tex.step;
			data->tex.tex_y = (int)(data->tex.tex_p) % 1024;
			my_mlx_pixel_put(x, y, data->t[index].addr[data->t[index].img_height
			* data->tex.tex_y + data->tex.tex_x], data);
		}
		else
			my_mlx_pixel_put(x, y, data->tex.floor, data);
		y++;
	}
}

void			draw_sprite(double *buff, t_data *data)
{
	int y;
	int x;

	x = data->srt.draw_sx - 1;
	while (x++ < data->srt.draw_ex)
	{
		data->srt.srt_x = (int)(256 * (x - (-data->srt.srt_w / 2
		+ data->srt.srt_pos_x)) * 528 / data->srt.srt_w) / 256;
		if (data->srt.tr_y > 0 && x > 0 && x < data->w_w
		&& data->srt.tr_y < buff[x])
		{
			y = data->srt.draw_sy + 1;
			while (y++ < data->srt.draw_ey)
			{
				data->srt.pixel = (y) * 256 - data->w_h * 128
				+ data->srt.srt_h * 128;
				data->srt.srt_y = ((data->srt.pixel * data->t[4].img_height)
				/ data->srt.srt_h) / 256;
				data->rgb.color = data->t[4].addr[data->t[4].img_width
				* data->srt.srt_y + data->srt.srt_x];
				if ((data->rgb.color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(x, y, data->rgb.color, data);
			}
		}
	}
}

void			save_frame(t_data *data)
{
	double buff[data->w_w];

	ray_casting(buff, data);
	if (data->srt.hit == 1)
		brain_sprite(buff, data);
	draw_map(data);
	draw_player(data);
}
