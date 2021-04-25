/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:49:24 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:44:13 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		load_xpm(t_data *data)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!(data->t[i].img = mlx_xpm_file_to_image(data->mlx,
		data->t[i].r_path, &data->t[i].img_width, &data->t[i].img_height)))
		{
			exit_error(11, data);
			return (0);
		}
		(data->t[i].addr = (int*)mlx_get_data_addr(data->t[i].img,
		&data->t[i].bits_per_pixel, &data->t[i].line_length,
		&data->t[i].endian));
		i++;
	}
	return (1);
}
