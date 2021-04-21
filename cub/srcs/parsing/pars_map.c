/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:39:51 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/18 17:38:38 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_map_space(t_data *data)
{
	int x;
	int y;

	y = 1;
	while (y < data->maps.m_y - 1)
	{
		x = 1;
		while (x < data->maps.m_x - 1)
		{
			if (data->map[y][x] == '0')
			{
				if (data->map[y][x-1] == ' ' || data->map[y][x+1] == ' ' || data->map[y-1][x] == ' ' || data->map[y+1][x] == ' ')
					return (0);
			}
			else if (data->map[y][x] == ' ')
			{
				if (data->map[y][x-1] == '0' || data->map[y][x+1] == '0' || data->map[y-1][x] == '0' || data->map[y+1][x] == '0')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}


static void ft_get_map_2(char *str, int index, t_data *data)
{
	int i;

	i = 0;
	data->maps.m_x++; 
	data->map[index] = (char*)malloc(sizeof(char) * data->maps.m_x + 1);
	ft_bzero(data->map[index], data->maps.m_x + 1);
	while(str[i])
	{
		data->map[index][i] = str[i];
		i++;
	}
	if (i < data->maps.m_x)
	{
		while (i < data->maps.m_x)
		{
			data->map[index][i] = ' ';
			i++;
		}
	}
	data->map[index][i] = '\0';
}

int		ft_get_map(int index, t_data *data)
{
	int i;

	i = 0;
	while (c_in_str(data->tab[index][0], " 012") == 0)
	{
		if (data->tab[index][0] != 0)	
			return (0);
		index++;
	}
	data->map = (char**)malloc(sizeof(char*) * (data->maps.m_y + 1));
	while (data->tab[index + i] && i < data->maps.m_y)
	{
		ft_get_map_2(data->tab[index + i], i, data);
		if (data->map[i] == NULL)
		{
			ft_free(data->map);
			return (0);
		}
		i++;
	}
	data->map[i] = NULL;
	if (check_map_space(data) == 1)
	{
		init_map_and_cam(data);
		return (1);
	}
	return (0);
}