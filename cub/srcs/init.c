/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:07:50 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 03:44:18 by hedi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->w_h = -1;
	data->w_w = -1;
	data->err = 0;
	data->tab = NULL;
	data->map = NULL;
	data->tex.r_path[0] = NULL;
	data->tex.r_path[1] = NULL;
	data->tex.r_path[2] = NULL;
	data->tex.r_path[3] = NULL;
	data->tex.r_path[4] = NULL;
	data->tex.tex[0] = NULL;
	data->tex.tex[1] = NULL;
	data->tex.tex[2] = NULL;
	data->tex.tex[3] = NULL;
	data->tex.tex[4] = NULL;
	data->tex.floor = -1;
	data->tex.ceiling = -1;
	data->maps.m_x = 0;
	data->maps.m_y = 0;

}

void	init_map_and_cam(t_data *data)
{
	data->maps.r_map = 0.25;
	data->maps.map_w = (int)(data->w_w * data->maps.r_map);
	data->maps.map_h = (int)(data->w_h * data->maps.r_map);
	data->maps.map_x = (int)(data->maps.map_w) / (data->maps.m_x);
	data->maps.map_y = (int)(data->maps.map_h) / (data->maps.m_y);
	data->cam.speed = 0.15;
	data->cam.rot_speed = 0.1;
}

void	init_data_sprite(t_data *data)
{
	data->srt.m_inv = 0;
	data->srt.tr_x = 0;
	data->srt.tr_y = 0;
	data->srt.srt_pos_x = 0;
	data->srt.srt_h = 0;
	data->srt.draw_sy = 0;
	data->srt.draw_ey = 0;
	data->srt.srt_w = 0;
	data->srt.draw_sx = 0;
	data->srt.draw_ex = 0;
	data->srt.srt_x = 0;
	data->srt.draw_sy = 0;
	data->srt.draw_ey = 0;
	data->srt.pixel = 0;
    data->srt.srt_y  = 0;
    data->srt.color = 0;
}