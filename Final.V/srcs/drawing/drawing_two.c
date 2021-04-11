/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:19:26 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/11 17:37:39 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void 			draw_player(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map.map_h)
	{
		x = 0;
		while(x < data->map.map_w)
		{
			if((y >= (data->cam.posy * data->map.map_y) - (data->map.map_y / 5)
			&& y <= ((data->cam.posy * data->map.map_y) + (data->map.map_y / 5)))
			&& (x >= (data->cam.posx * data->map.map_x) - (data->map.map_x / 5)
			&& x <= ((data->cam.posx * data->map.map_x) + (data->map.map_x / 5))))
				my_mlx_pixel_put(x, y, 0x696969, data);
			x++;
		}
		y++;
	}
}

static void            draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	px = py = 0;
	int i = 0;
	while (py < data->map.m_y)
	{
		x = 1;
		while (px < data->map.m_x && x < data->map.map_w)
		{
			if (x % (int)data->map.map_x == 0)
			{
				px++;
				x++;
			}
			if (data->maps[py][px] && data->maps[py][px] == '1')
				my_mlx_pixel_put(x, y, 0x2F4F4F, data);
			else if (data->maps[py][px] == '2')
				my_mlx_pixel_put(x, y, 0xD3D3D3, data);
			else if (data->maps[py][px] == '0')
				my_mlx_pixel_put(x, y, 0x99D8D89, data);
			x++;
		}
		y++;
		px = 0;
		if ((y % (int)data->map.map_y) == 0)
		{
			py++;
			y++;
		}
	}
}

void	draw_sprite(int *srt, t_data *data)
{
	int y;

	y = 0;
	data->srt.stripe = data->srt.draw_sx;
	while (data->srt.stripe < data->srt.draw_ex)
	{
		data->srt.srt_x = (int)(256 * (data->srt.stripe - (-data->srt.srt_w / 2 + data->srt.srt_pos_x)) * 528 / data->srt.srt_w) / 256;
		if (data->srt.tr_y > 0 && data->srt.stripe > 0 && data->srt.stripe < data->w_w && data->srt.tr_y < data->cast.buff[data->srt.stripe])
		{
			y = data->srt.draw_sy;
			while  (y < data->srt.draw_ey)
			{
				data->srt.pixel = (y) * 256 - data->w_h * 128 + data->srt.srt_h * 128;
        		data->srt.srt_y  = ((data->srt.pixel * 797) / data->srt.srt_h) / 256;
        		data->srt.color = srt[528* data->srt.srt_y + data->srt.srt_x];
           		if ((data->srt.color  & 0x00FFFFFF) != 0)
			   		my_mlx_pixel_put(data->srt.stripe, y,  data->srt.color, data);
				y++;
			}
		}
		data->srt.stripe++;
	}
}


int		render_next_frame(int keycode, t_data *data)
{
	action_key(keycode, data);
	ray_casting(data);
	if (data->srt.hit == 1)
		sprite(data->tex.tex[4],  data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}