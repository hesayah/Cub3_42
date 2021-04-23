/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:19:26 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/15 16:47:52 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void 			draw_player(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->maps.map_h)
	{
		x = 0;
		while(x < data->maps.map_w)
		{
			if((y >= (data->cam.posy * data->maps.map_y) - (data->maps.map_y / 5)
			&& y <= ((data->cam.posy * data->maps.map_y) + (data->maps.map_y / 5)))
			&& (x >= (data->cam.posx * data->maps.map_x) - (data->maps.map_x / 5)
			&& x <= ((data->cam.posx * data->maps.map_x) + (data->maps.map_x / 5))))
				my_mlx_pixel_put(x, y, 0x696969, data);
			x++;
		}
		y++;
	}
}

void            draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	px = py = 0;
	int i = 0;
	while (py < data->maps.m_y)
	{
		x = 1;
		while (px < data->maps.m_x && x < data->maps.map_w)
		{
			if (x % (int)data->maps.map_x == 0)
			{
				px++;
				x++;
			}
			if (data->map[py][px] && data->map[py][px] == '1')
				my_mlx_pixel_put(x, y, 0x2F4F4F, data);
			else if (data->map[py][px] == '2')
				my_mlx_pixel_put(x, y, 0xD3D3D3, data);
			else if (data->map[py][px] == '0')
				my_mlx_pixel_put(x, y, 0x99D8D89, data);
			x++;
		}
		y++;
		px = 0;
		if ((y % (int)data->maps.map_y) == 0)
		{
			py++;
			y++;
		}
	}
}

void	draw_sprite(int *srt, double *buff, t_data *data)
{
	int y;
	int x;

	y = 0;
	x = data->srt.draw_sx;
	while (x < data->srt.draw_ex)
	{
		data->srt.srt_x = (int)(256 * (x - (-data->srt.srt_w / 2 + data->srt.srt_pos_x)) * 528 / data->srt.srt_w) / 256;
		if (data->srt.tr_y > 0 && x > 0 && x < data->w_w && data->srt.tr_y < buff[x])
		{
			y = data->srt.draw_sy + 2;
			while  (y < data->srt.draw_ey)
			{
				data->srt.pixel = (y) * 256 - data->w_h * 128 + data->srt.srt_h * 128;
        		data->srt.srt_y  = ((data->srt.pixel * 797) / data->srt.srt_h) / 256;
        		data->srt.color = srt[528* data->srt.srt_y + data->srt.srt_x];
           		if ((data->srt.color  & 0x00FFFFFF) != 0)
			   		my_mlx_pixel_put(x, y,  data->srt.color, data);
				y++;
			}
		}
		x++;
	}
}


int		render_next_frame(t_data *data)
{
	double buff[data->w_w];

	ray_casting(buff, data);
	if (data->srt.hit == 1)
		brain_sprite(data->tex.tex[4], buff,  data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}