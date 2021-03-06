/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:26:03 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:27:37 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	void	define_vector_bis(double plane_x, double plane_y, t_data *data)
{
	data->cam.plane_x = plane_x;
	data->cam.plane_y = plane_y;
}

static	void	define_vector(t_data *data)
{
	if (data->cam.dir_eye == M_PI / 2)
		define_vector_bis(-0.66, 0, data);
	else if (data->cam.dir_eye == -M_PI / 2)
		define_vector_bis(0.66, 0, data);
	else if (data->cam.dir_eye == 0)
		define_vector_bis(0, 0.66, data);
	else if (data->cam.dir_eye == M_PI)
		define_vector_bis(0, -0.66, data);
	data->cam.dir_x = cos(data->cam.dir_eye);
	data->cam.dir_y = sin(data->cam.dir_eye);
}

static	void	get_first_player_pos_two(int y, int x, t_data *data)
{
	if (data->map[y][x] == '2')
		data->maps.n_srt++;
	else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
	|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
	{
		if (data->map[y][x] == 'S')
			data->cam.dir_eye = M_PI / 2;
		else if (data->map[y][x] == 'N')
			data->cam.dir_eye = (-M_PI / 2);
		else if (data->map[y][x] == 'E')
			data->cam.dir_eye = 0;
		else if (data->map[y][x] == 'W')
			data->cam.dir_eye = M_PI;
		data->map[y][x] = '0';
		data->cam.posy = y + 0.5;
		data->cam.posx = x + 0.5;
		define_vector(data);
		data->maps.spown++;
	}
}

void			get_first_player_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	data->maps.spown = 0;
	data->maps.n_srt = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			get_first_player_pos_two(y, x, data);
			x++;
		}
		y++;
	}
	if (data->maps.spown != 1)
		return (exit_error(10, data));
	if (data->maps.n_srt > 0)
		init_sprite(data);
}
