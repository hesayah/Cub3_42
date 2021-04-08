/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:07:50 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/08 15:02:31 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_data(t_data *data)
{
	data->w_h = -1;
	data->w_w = -1;
	data->tex.r_path[0] = NULL;
	data->tex.r_path[1] = NULL;
	data->tex.r_path[2] = NULL;
	data->tex.r_path[3] = NULL;
	data->tex.r_path[4] = NULL;
	data->tex.floor = -1;
	data->tex.ceiling = -1;
}

void	init_map_and_cam(t_data *data)
{
   	data->map.m_x = 0;
	data->map.m_y = 0;
	data->map.r_map = 0.25;
	data->map.map_w = (int)(data->w_w * data->map.r_map);
	data->map.map_h = (int)(data->w_h * data->map.r_map);
	data->map.map_x = (int)(data->map.map_w) / (data->map.m_x);
	data->map.map_y = (int)(data->map.map_h) / (data->map.m_y);
	data->cam.speed = 0.15;
	data->cam.rot_speed = 0.1;
}