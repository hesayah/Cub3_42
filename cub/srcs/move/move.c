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
	if (keycode == 97)
	{
		if (data->map[(int)(data->cam.posy)][(int)(data->cam.posx
		- data->cam.dir_y * data->cam.speed)] == '0')
			data->cam.posx -= data->cam.dir_y * data->cam.speed;
		if (data->map[(int)(data->cam.posy + data->cam.dir_x
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy += data->cam.dir_x * data->cam.speed;
	}
	if (keycode == 100)
	{
		if (data->map[(int)(data->cam.posy)][(int)(data->cam.posx
		+ data->cam.dir_y * data->cam.speed)] == '0')
			data->cam.posx += data->cam.dir_y * data->cam.speed;
		if (data->map[(int)(data->cam.posy - data->cam.dir_x
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy -= data->cam.dir_x * data->cam.speed;
	}
}

static	void	move_two(int keycode, t_data *data)
{
	if (keycode == 115)
	{
		if (data->map[(int)(data->cam.posy)][(int)(data->cam.posx
		+ data->cam.dir_x * data->cam.speed)] == '0')
			data->cam.posx += data->cam.dir_x * data->cam.speed;
		if (data->map[(int)(data->cam.posy + data->cam.dir_y
		* data->cam.speed)][(int)(data->cam.posx)] == '0')
			data->cam.posy += data->cam.dir_y * data->cam.speed;
	}
	if (keycode == 119)
	{
		if (data->map[(int)(data->cam.posy)][(int)(data->cam.posx
		- data->cam.dir_x * data->cam.speed)] == '0')
			data->cam.posx -= data->cam.dir_x * data->cam.speed;
		if (data->map[(int)(data->cam.posy - data->cam.dir_y
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
	if (keycode == 65361)
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
	else if (keycode == 65363)
		move_one(keycode, data);
	else if (keycode == 119 || keycode == 115)
		move_two(keycode, data);
	else
		move_three(keycode, data);
}

int		action_key(int keycode, t_data *data)
{
	printf("keycode == [%i]\n", keycode);
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115 ||
	keycode == 65361 || keycode == 65363)
		brain_move(keycode, data);
	render_next_frame(data);
	return (0);
}