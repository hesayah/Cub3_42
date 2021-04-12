/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:31:57 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/12 18:20:51 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	sort_srt(t_data *data)
{
	int i;
	t_sprite tmp;

	i = 0;
	while (i < data->map.n_srt)
	{
		data->sprite[i].dist = (pow(data->cam.posy - data->sprite[i].y, 2) + pow(data->cam.posx - data->sprite[i].x, 2));
		i++;
	}
	i = 0;
	while (i < data->map.n_srt - 1)
	{
		if (data->sprite[i].dist < data->sprite[i + 1].dist)
		{
			tmp = data->sprite[i + 1];
			data->sprite[i + 1] = data->sprite[i];
			data->sprite[i] = tmp;
			i = 0;
		}
		i++;
	}
}

void sprite(int *srt, t_data *data)
{
	int i;
	int	y;
	
	i = 0;
	sort_srt(data);
	while(i < data->map.n_srt)
	{
		data->srt.sprite_x = data->sprite[i].x  - data->cam.posx;
		data->srt.sprite_y = data->sprite[i].y  - data->cam.posy;
		printf("APRES [%f] && i == [%i]\n", data->sprite[i].dist, i);
		data->srt.m_inv = 1.0 / (data->cam.plane_x * data->cam.dir_y - data->cam.dir_x  * data->cam.plane_y);
		data->srt.tr_x = data->srt.m_inv * (data->cam.dir_y * data->srt.sprite_x  - data->cam.dir_x * data->srt.sprite_y);
		data->srt.tr_y = data->srt.m_inv * (-data->cam.plane_y * data->srt.sprite_x  + data->cam.plane_x * data->srt.sprite_y);
		data->srt.srt_pos_x = ((int)((data->w_w / 2) * (1 + data->srt.tr_x / data->srt.tr_y)));
		data->srt.srt_h = abs((int)(data->w_h / (data->srt.tr_y)));
		data->srt.draw_sy = -data->srt.srt_h / 2 + data->w_h / 2;
		if (data->srt.draw_sy < 0)
			data->srt.draw_sy = 0;
		data->srt.draw_ey= data->srt.srt_h / 2 + (data->w_h / 2);
		if (data->srt.draw_ey>= data->w_h)
			data->srt.draw_ey= data->w_h - 1;
		data->srt.srt_w = abs((int)(data->w_h/data->srt.tr_y));
		data->srt.draw_sx = (-data->srt.srt_w / 2) + data->srt.srt_pos_x;
		if (data->srt.draw_sx < 0)
			data->srt.draw_sx = 0;
		data->srt.draw_ex = (data->srt.srt_w / 2) + data->srt.srt_pos_x;
		if (data->srt.draw_ex >= data->w_w )
			data->srt.draw_ex = data->w_w - 1;
		data->srt.stripe = data->srt.draw_sx;
		draw_sprite(srt,  data);
		i++;
	}
}

int brain_sprite(t_data *data)
{
	int x;
	int	y;
	int i;

	y = 0;
	i = 0;
    if (!(data->sprite = malloc(sizeof(t_sprite) * data->map.n_srt)))
        return (exit_error(-10, data));
	while (data->maps[y] != NULL)
	{
		x = 0;
		while (data->maps[y][x] != '\0')
		{
			if (data->maps[y][x] == '2')
			{
				data->sprite[i].x = x + 0.5;
				data->sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	init_sprite(data);
    return (0);
}