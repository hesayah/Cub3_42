/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:39:51 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/08 15:01:55 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char *ft_get_map_2(char *str, t_data *data)
{
	int i;
	char *new;

	i = 0;
	new = (char*)malloc(sizeof(char) * data->map.m_x + 1);
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (i < data->map.m_x)
	{
		while (i < data->map.m_x)
		{
			new[i] = ' ';
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

int		ft_get_map(t_data *data, int index)
{
	int i;

	i = 0;
	data->maps = (char**)malloc(sizeof(char*) * (data->map.m_y + 1));
	while (c_in_str(data->tab[index][0], " 012") == 0)
		index++;
	while (data->tab[index + i] && i < data->map.m_y)
	{
		data->maps[i] = ft_get_map_2(data->tab[index + i], data);
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