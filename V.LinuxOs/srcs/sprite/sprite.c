/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:31:57 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:39:33 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	sort_sprite(t_data *data)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < data->maps.n_srt)
	{
		data->sprite[i].dist = (pow(data->cam.posy - data->sprite[i].y, 2) +
		pow(data->cam.posx - data->sprite[i].x, 2));
		i++;
	}
	i = 0;
	while (i < data->maps.n_srt - 1)
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

void			sprite_calc(int i, t_data *data)
{
	data->srt.sprite_x = data->sprite[i].x - data->cam.posx;
	data->srt.sprite_y = data->sprite[i].y - data->cam.posy;
	data->srt.m_inv = 1.0 / (data->cam.plane_x * data->cam.dir_y
	- data->cam.dir_x * data->cam.plane_y);
	data->srt.tr_x = data->srt.m_inv * (data->cam.dir_y * data->srt.sprite_x
	- data->cam.dir_x * data->srt.sprite_y);
	data->srt.tr_y = data->srt.m_inv * (-data->cam.plane_y * data->srt.sprite_x
	+ data->cam.plane_x * data->srt.sprite_y);
	data->srt.srt_pos_x = ((int)((data->w_w / 2) *
	(1 + data->srt.tr_x / data->srt.tr_y)));
	data->srt.srt_h = abs((int)(data->w_h / (data->srt.tr_y)));
	data->srt.draw_sy = -data->srt.srt_h / 2 + data->w_h / 2;
	if (data->srt.draw_sy < 0)
		data->srt.draw_sy = 0;
	data->srt.draw_ey = data->srt.srt_h / 2 + (data->w_h / 2);
	if (data->srt.draw_ey >= data->w_h)
		data->srt.draw_ey = data->w_h - 1;
	data->srt.srt_w = abs((int)(data->w_h / data->srt.tr_y));
}

void			brain_sprite(double *buff, t_data *data)
{
	int i;
	int	y;

	i = 0;
	sort_sprite(data);
	while (i < data->maps.n_srt)
	{
		sprite_calc(i, data);
		data->srt.draw_sx = (-data->srt.srt_w / 2) + data->srt.srt_pos_x;
		if (data->srt.draw_sx < 0)
			data->srt.draw_sx = 0;
		data->srt.draw_ex = (data->srt.srt_w / 2) + data->srt.srt_pos_x;
		if (data->srt.draw_ex >= data->w_w)
			data->srt.draw_ex = data->w_w - 1;
		draw_sprite(buff, data);
		i++;
	}
}

void			init_sprite(t_data *data)
{
	int x;
	int	y;
	int i;

	if (!(data->sprite = malloc(sizeof(t_sprite) * data->maps.n_srt)))
		return (exit_error(-1, data));
	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '2')
			{
				data->sprite[i].x = x + 0.5;
				data->sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	init_data_sprite(data);
}
