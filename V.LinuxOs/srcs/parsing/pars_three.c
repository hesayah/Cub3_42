/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:27:26 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 09:04:10 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		c_in_str(char c, char *s2)
{
	int i;

	i = 0;
	if (!c || !s2)
		return (0);
	while (s2[i] != '\0')
	{
		if (c == s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	get_res_two(int i, char *str, t_data *data)
{
	while (str[i] && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			data->w_h = ft_atoi(str + i);
			break ;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (exit_error(3, data));
		i++;
	}
}

void	get_res(char *str, t_data *data)
{
	int i;

	i = 2;
	while (str[i] && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			data->w_w = ft_atoi(str + i);
			break ;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != ' ')
		return (exit_error(3, data));
	get_res_two(i, str, data);
}

void	get_path_tex(int index, char *str, t_data *data)
{
	int		i;
	int		fd;
	char	*tmp;

	if (data->t[index].r_path != NULL)
		return (exit_error(4, data));
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	data->t[index].r_path = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(data->t[index].r_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR : [", 0);
		ft_putstr_fd(data->t[index].r_path, 0);
		ft_putstr_fd("] : NOT FOUND\n", 0);
		return (exit_error(3, data));
	}
}
