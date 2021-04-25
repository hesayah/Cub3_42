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

unsigned	long	ft_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ((int)(-1));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void				draw_player(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->maps.map_h)
	{
		x = 0;
		while (x < data->maps.map_w)
		{
			if ((y >= data->cam.posy * data->maps.map_y - data->maps.map_y / 5
			&& y <= data->cam.posy * data->maps.map_y + data->maps.map_y / 5)
			&& (x >= data->cam.posx * data->maps.map_x - data->maps.map_x / 5
			&& x <= data->cam.posx * data->maps.map_x + data->maps.map_x / 5))
				my_mlx_pixel_put(x, y, 0x696969, data);
			x++;
		}
		y++;
	}
}

/*static	void		draw_map_two(int x, int y, int px, int py, t_data *data)
*{
*
*}
*/

void				draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	py = 0;
	while (py < data->maps.m_y)
	{
		x = 1;
		px = 0;
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
		if ((y % (int)data->maps.map_y) == 0)
		{
			py++;
			y++;
		}
	}
}

int					render_next_frame(t_data *data)
{
	double buff[data->w_w];

	ray_casting(buff, data);
	if (data->srt.hit == 1)
		brain_sprite(buff, data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
