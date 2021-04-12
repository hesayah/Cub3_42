/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:39:51 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/09 16:46:32 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void ft_get_map_2(char *str, int index, t_data *data)
{
	int i;

	i = 0;
	data->maps[index] = (char*)malloc(sizeof(char) * data->map.m_x + 1);
	while(str[i])
	{
		data->maps[index][i] = str[i];
		i++;
	}
	if (i < data->map.m_x)
	{
		while (i < data->map.m_x)
		{
			data->maps[index][i] = ' ';
			i++;
		}
	}
	data->maps[index][i] = '\0';
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
	data->maps = (char**)malloc(sizeof(char*) * (data->map.m_y + 1));
	while (data->tab[index + i] && i < data->map.m_y)
	{
		ft_get_map_2(data->tab[index + i], i, data);
		if (data->maps[i] == NULL)
		{
			ft_free(data->maps);
			return (0);
		}
		i++;
	}
	data->maps[i] = NULL;
	init_map_and_cam(data);
	return (1);
}