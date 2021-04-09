/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_brain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:12:51 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/09 16:46:22 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_multi_map(int j, t_data *data)
{
	int		i;

	i = 0;
	while (data->tab[i] && c_in_str(data->tab[i][0], " 012") == 0)
		i++;
	while (data->tab[i] && c_in_str(data->tab[i][0], " 012") == 1)
	{
		if (data->map.m_x < ft_strlen(data->tab[i]))
			data->map.m_x = ft_strlen(data->tab[i]);
		i++;
		data->map.m_y++;
	}
	while (data->tab[i])
	{
		if (c_in_str(data->tab[i][0], " 012") == 1)
			return (0);
		i++;
	}
	ft_putstr_fd("TEST MULTIMAP : OK\n", 0);
	return (1);
}

static int	get_nb(char *file)
{

	int		i;
	int		fd;
	char	*line;
	
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	free(line);
    close(fd);
	return (i);
}

int			pars_brain(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	j = get_nb(file);
	data->tab = (char**)malloc(sizeof(char*) * j + 1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->tab[i] = ft_strdup(line);
	data->tab[i + 1] = NULL;
	free(line);
	if (check_multi_map(j, data) == 1)
		return (pars_value_line(data));
	return (0);
}