/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:49:24 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/09 16:45:52 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		get_tex(t_data *data)
{
	 if ((data->tex.xpm = mlx_xpm_file_to_image(data->mlx, data->tex.r_path[3],
	 &data->tex.img_width, &data->tex.img_height)) != NULL)
		(data->tex.tex_ea = (int*)mlx_get_data_addr(data->tex.xpm, 
		&data->tex.bits_per_pixel, &data->tex.line_length, &data->tex.endian));
	if ((data->tex.xpm = mlx_xpm_file_to_image(data->mlx, data->tex.r_path[1], 
	&data->tex.img_width, &data->tex.img_height)) != NULL)
		(data->tex.tex_so= (int*)mlx_get_data_addr(data->tex.xpm, 
		&data->tex.bits_per_pixel, &data->tex.line_length, &data->tex.endian));
	if ((data->tex.xpm = mlx_xpm_file_to_image(data->mlx, data->tex.r_path[2], 
	&data->tex.img_width, &data->tex.img_height)) != NULL)
		(data->tex.tex_we = (int*)mlx_get_data_addr(data->tex.xpm, 
		&data->tex.bits_per_pixel, &data->tex.line_length, &data->tex.endian));
	if ((data->tex.xpm = mlx_xpm_file_to_image(data->mlx, data->tex.r_path[0],
	&data->tex.img_width, &data->tex.img_height)) != NULL)
		(data->tex.tex_no = (int*)mlx_get_data_addr(data->tex.xpm, 
		&data->tex.bits_per_pixel, &data->tex.line_length, &data->tex.endian));
	return (1);
}

int		get_sprite(t_data *data)
{
	if ((data->tex.xpm = mlx_xpm_file_to_image(data->mlx, data->tex.r_path[4],
	&data->tex.img_width, &data->tex.img_height)) != NULL)
		(data->tex.tex_s = (int*)mlx_get_data_addr(data->tex.xpm, 
		&data->tex.bits_per_pixel, &data->tex.line_length, &data->tex.endian));
	return (1);
}

int		load_xpm(t_data *data)
{
	if (get_tex(data) == 0)
	{
		ft_putstr_fd("ERROR : LOAD TEX\n", 0);
		return (0);
	}
	if (get_sprite(data) == 0)
	{
		ft_putstr_fd("ERROR : LOAD SPRITE\n", 0);
		return (0);
	}
	ft_putstr_fd("LOAD XPM : OK\n", 0);
	ft_putstr_fd("HAVE FUN ;)! \n", 0);
	return (1);
}