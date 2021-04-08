/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:58:15 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/08 15:01:00 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_value(t_data *data)
{
	if ((data->w_w < 300 || data->w_w > 2560)
	|| (data->w_h < 300 || data->w_h > 1440))
		return (0);
	if (data->tex.r_path[0] == NULL || data->tex.r_path[1] == NULL
		|| data->tex.r_path[2] == NULL || data->tex.r_path[3]== NULL
		|| data->tex.r_path[4] == NULL)
		return (0);
	if (data->tex.floor == -1 || data->tex.ceiling == -1)
		return(exit_error(6, data));
	return (1);
}

static int get_clg_flr_value_2(char *str, int i, t_data *data)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] && str[i] == ','))
		return (0);
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
	return (1);
}

static int get_clg_flr_value(char *str, t_data *data)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	data->rgb.r = ft_atoi(str + 2);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] && str[i] == ','))
		return (0);
	data->rgb.g = ft_atoi(str + i + 1);
	i++;
	return (get_clg_flr_value_2(str, i, data));
    return (1);
}

int		scan_id(char *str, t_data *data)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		return(get_res(str, data));
	if (ft_strncmp(str, "NO ", 3) == 0)
		return(get_path_tex(0, str, data));
	if (ft_strncmp(str, "SO ", 3) == 0)
		return(get_path_tex(1, str, data));
	if (ft_strncmp(str, "WE ", 3) == 0)
		return(get_path_tex(2, str, data));
	if (ft_strncmp(str, "EA ", 3) == 0)
		return(get_path_tex(3, str, data));
	if (ft_strncmp(str, "S ", 2) == 0)
		return(get_path_tex(4, str, data));
	if(ft_strncmp(str, "C " , 2) == 0 ||
	ft_strncmp(str,"F " , 2) == 0)
		return(get_clg_flr_value(str, data));
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
			printf("ici bug == [%s]\n", data->tab[i]);
			if (scan_id(data->tab[i], data) == 0)
				return(exit_error(4, data));
		}
		
		else if ((int)(data->tab[i][0]) != 0)
		{
			
			return(exit_error(4, data));
		}
		i++;
	}
	if (check_value(data) == 0)
		return (0);
	else
		return(ft_get_map(data, i));
	return (1);
}