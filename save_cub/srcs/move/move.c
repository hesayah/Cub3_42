/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:34:45 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/11 13:37:55 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	move_three(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		if (data->maps[(int)(data->cam.posy)][(int)(data->cam.posx
		- data->cam.dir_y * data->cam.speed)] == '0')
			data->cam.posx -= data->cam.dir_y * data->cam.speed;
		if (data->maps[(int)(data->cam.posy + data->cam.dir_x
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy += data->cam.dir_x * data->cam.speed;
	}
	if (keycode == 0)
	{
		if (data->maps[(int)(data->cam.posy)][(int)(data->cam.posx
		+ data->cam.dir_y * data->cam.speed)] == '0')
			data->cam.posx += data->cam.dir_y * data->cam.speed;
		if (data->maps[(int)(data->cam.posy - data->cam.dir_x
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy -= data->cam.dir_x * data->cam.speed;
	}
}

static	void	move_two(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		if (data->maps[(int)(data->cam.posy)][(int)(data->cam.posx
		+ data->cam.dir_x * data->cam.speed)] == '0')
			data->cam.posx += data->cam.dir_x * data->cam.speed;
		if (data->maps[(int)(data->cam.posy + data->cam.dir_y
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy += data->cam.dir_y * data->cam.speed;
	}
	if (keycode == 1)
	{
		if (data->maps[(int)(data->cam.posy)][(int)(data->cam.posx
		- data->cam.dir_x * data->cam.speed)] == '0')
			data->cam.posx -= data->cam.dir_x * data->cam.speed;
		if (data->maps[(int)(data->cam.posy - data->cam.dir_y
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy -= data->cam.dir_y * data->cam.speed;
	}
}

static	void	move_one(int keycode, t_data *data)
{
	data->cam.old_dir_x = data->cam.dir_x;
	data->cam.dir_x = data->cam.dir_x * cos(data->cam.rot_speed)
	- data->cam.dir_y * sin(data->cam.rot_speed);
	data->cam.dir_y = data->cam.old_dir_x * sin(data->cam.rot_speed)
	+ data->cam.dir_y * cos(data->cam.rot_speed);
	data->cam.old_plane_x = data->cam.plane_x;
	data->cam.plane_x = data->cam.plane_x * cos(data->cam.rot_speed)
	- data->cam.plane_y * sin(data->cam.rot_speed);
	data->cam.plane_y = data->cam.old_plane_x * sin(data->cam.rot_speed)
	+ data->cam.plane_y * cos(data->cam.rot_speed);
}

static void			brain_move(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->cam.old_dir_x = data->cam.dir_x;
		data->cam.dir_x = data->cam.dir_x * cos(-data->cam.rot_speed)
		- data->cam.dir_y * sin(-data->cam.rot_speed);
		data->cam.dir_y = data->cam.old_dir_x * sin(-data->cam.rot_speed)
		+ data->cam.dir_y * cos(-data->cam.rot_speed);
		data->cam.old_plane_x = data->cam.plane_x;
		data->cam.plane_x = data->cam.plane_x * cos(-data->cam.rot_speed)
		- data->cam.plane_y * sin(-data->cam.rot_speed);
		data->cam.plane_y = data->cam.old_plane_x * sin(-data->cam.rot_speed)
		+ data->cam.plane_y * cos(-data->cam.rot_speed);
	}
	else if (keycode == 124)
		move_one(keycode, data);
	else if (keycode == 1 || keycode == 13)
		move_two(keycode, data);
	else
		move_three(keycode, data);
}

int		action_key(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 ||
	keycode == 123 || keycode == 124)
		brain_move(keycode, data);
	return (0);
}