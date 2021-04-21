/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_brain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:12:51 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 04:42:01 by hedi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_map_two(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (c_in_str(tab[i], " 012NSEW") == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_value_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->tab[i] && (c_in_str(data->tab[i][0], "RNSWEFC") == 1 || (int)data->tab[i][0] == 0))
		i++;
	while (data->tab[i] && c_in_str(data->tab[i][0], " 012") == 1)
	{
		if (check_map_two(data->tab[i]) ==  0)
			return (0);
		if (data->maps.m_x < ft_strlen(data->tab[i]))
			data->maps.m_x = ft_strlen(data->tab[i]);
		i++;
		data->maps.m_y++;
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

int	get_nb(char *file)
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

	i = get_nb(file);
	fd = open(file, O_RDONLY);
	data->tab = (char**)malloc(sizeof(char*) * (i + 1));
	ft_memset(data->tab, 0, i + 1);
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
	ft_debug(data);
	/*if (check_value_map(data) == 1)
		pars_value_line(data);
	else
		return (0);*/
	return (1);
}