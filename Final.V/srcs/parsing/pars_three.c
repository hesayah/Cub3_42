/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:27:26 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/09 16:46:43 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int c_in_str(char c, char *s2)
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

int		get_res(char *str, t_data *data)
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
        return (exit_error(2, data));
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
            return (exit_error(2, data));
        i++;
    }
	return (1);
}


int	get_path_tex(int index, char *str, t_data *data)
{
	int i;
	int fd;
    char *tmp;
	
    if (data->tex.r_path[index] != NULL)
        return (0);
    i = 0;
	while (str[i] && str[i] != ' ')
		i++;
    while (str[i] && str[i] == ' ')
		i++;
	data->tex.r_path[index] =   ft_substr(str, i, ft_strlen(str) - i);
	fd = open(data->tex.r_path[index], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR : [", 0);
		ft_putstr_fd(data->tex.r_path[index], 0);
        ft_putstr_fd("] : NOT FOUND\n", 0);
        return(exit_error(3, data));
	}
    return (1);
}