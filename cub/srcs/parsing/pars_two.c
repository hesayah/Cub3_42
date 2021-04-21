/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:58:15 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:27:05 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_value(t_data *data)
{
	if ((data->w_w < 300 || data->w_w > 2560)
	|| (data->w_h < 300 || data->w_h > 1440))
		exit_error(6, data);
	if (data->tex.r_path[0] == NULL || data->tex.r_path[1] == NULL
		|| data->tex.r_path[2] == NULL || data->tex.r_path[3]== NULL
		|| data->tex.r_path[4] == NULL)
		exit_error(7, data);
	if (data->tex.floor == -1 || data->tex.ceiling == -1)
		exit_error(8, data);
}

static void get_clg_flr_value_2(char *str, int i, t_data *data)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] && str[i] == ','))
		return (exit_error(5, data));
	data->rgb.b = ft_atoi(str + i + 1);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (exit_error(5, data));
		i++;
	}
	if (ft_strncmp(str, "C ", 2) == 0)
		data->tex.ceiling = ft_rgb(data->rgb.r,data->rgb.g,data->rgb.b);
	else if (ft_strncmp(str, "F ", 2) == 0)
		data->tex.floor = ft_rgb(data->rgb.r,data->rgb.g,data->rgb.b);
}

static void get_clg_flr_value(char *str, t_data *data)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (exit_error(5, data));
	data->rgb.r = ft_atoi(str + 2);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] && str[i] == ','))
		return (exit_error(5, data));
	data->rgb.g = ft_atoi(str + i + 1);
	i++;
	get_clg_flr_value_2(str, i, data);
}

int		scan_id(char *str, t_data *data)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		get_res(str, data);
	else if (ft_strncmp(str, "NO ", 3) == 0)
		get_path_tex(0, str, data);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		get_path_tex(1, str, data);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		get_path_tex(2, str, data);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		get_path_tex(3, str, data);
	else if (ft_strncmp(str, "S ", 2) == 0)
		get_path_tex(4, str, data);
	else if(ft_strncmp(str, "C " , 2) == 0 ||
	ft_strncmp(str,"F " , 2) == 0)
		get_clg_flr_value(str, data);
	else
		return (0);
	return (1);
}

int pars_value_line(t_data *data)
{
	int i;

	i = 0;
	while (data->tab[i] && c_in_str(data->tab[i][0], " 012") == 0)
	{
		if (c_in_str(data->tab[i][0], "RNSWEFC") == 1)
		{
			if (scan_id(data->tab[i], data) == 0)
				exit_error(2, data);
		}
		else if ((int)(data->tab[i][0]) != 0)
			exit_error(2, data);
		i++;
	}
	check_value(data);
	//printf("err = [%i]\n", data->err);
	if (data->err == -1)
		return (clean_up(1, data));
	ft_get_map(i, data);
	if (data->err == -2)
		return (clean_up(2, data));
	return (1);
}