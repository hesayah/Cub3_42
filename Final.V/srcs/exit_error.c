/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:35:44 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/07 17:02:41 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int clean_up(int code, t_data *data)
{
    if (code == 2 || code == 3 || code == 4 || code == 5)
        ft_free(data->tab);
   // system("leaks cub3D");
    exit(0);
    return (0);
}


void    code_err(int code)
{
    if (code != 0)
        write(0, strerror(code), ft_strlen(strerror(code)));
    write(0, "\n", 1);
}

int    exit_error(int code, t_data *data)
{
    if (code == 1)
        ft_putstr_fd("ERROR : BAD EXTENTION\n", 0);
    if (code == 2)
        ft_putstr_fd("ERROR : PARSING GETTING RESOLUTION\n", 0);
    if (code == 3)
        ft_putstr_fd("ERROR : BAD PATH \n", 0);
    if (code == 4)
        ft_putstr_fd("ERROR PARSING : BAD INDICATOR OR VALUE\n", 0);
    if (code == 5)
        ft_putstr_fd("ERROR PARSING : CHECK COLOR LINE\n", 0);
    if (code == 6)
        ft_putstr_fd("ERROR PARSING : RGB < 0 || RGB > 255 ", 0);
    if (code == 7)
        ft_putstr_fd("ERROR : PARSING VALUE FALSE OR MISSING\n", 0);
    clean_up(code, data);
    return (0);
}