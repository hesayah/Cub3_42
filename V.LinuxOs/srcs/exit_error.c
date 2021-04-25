/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:35:44 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 11:31:54 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int clean_up(int code, t_data *data)
{
    if (data->tab)
        ft_free(data->tab);
    if (data->t[0].r_path)
        free(data->t[0].r_path);
    if (data->t[1].r_path)
        free(data->t[1].r_path);
    if (data->t[2].r_path)
        free(data->t[2].r_path);
    if (data->t[3].r_path)
        free(data->t[3].r_path);
    if (data->t[4].r_path)
        free(data->t[4].r_path);
    if (data->map)
        ft_free(data->map);;
    if (data->sprite)
        free(data->sprite);
    if (data->t[0].img)
        mlx_destroy_image(data->mlx, data->t[0].img);
    if (data->t[1].img)
        mlx_destroy_image(data->mlx, data->t[1].img);
    if (data->t[2].img)
        mlx_destroy_image(data->mlx, data->t[2].img);
    if (data->t[3].img)
        mlx_destroy_image(data->mlx, data->t[3].img);
    if (data->t[4].img)
        mlx_destroy_image(data->mlx, data->t[4].img);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}


void    code_err(int code)
{
    if (code != 0)
        write(0, strerror(code), ft_strlen(strerror(code)));
    write(0, "\n", 1);
}

void    exit_error(int code, t_data *data)
{
    if (code == -1)
        ft_putstr_fd("ERROR : MALLOC FAIL\n", 0);
    if (code == 0)
        ft_putstr_fd("ERROR : BAD EXTENTION OR EMPTY\n", 0);
    if (code == 1)
        ft_putstr_fd("ERROR : PARSING MAP WRONG INPUT\n", 0);
    if (code == 2)
        ft_putstr_fd("ERROR : PARSING WRONG ID\n", 0);
    if (code == 3)
        ft_putstr_fd("ERROR : PARSING GETTING RESOLUTION\n", 0);
    if (code == 4)
        ft_putstr_fd("ERROR : PARSING MULTIPLE PATH TEXTURE\n", 0);
    if (code == 5)
        ft_putstr_fd("ERROR : PARSING CHECK COLORS LINES\n", 0);
    if (code == 6)
        ft_putstr_fd("ERROR : PARSING  RES < SIZE_MIN || RES > SIZE_MAX\n", 0);
    if (code == 7)
        ft_putstr_fd("ERROR : PARSING PATH TEXTURES MISSING\n", 0);
    if (code == 8)
        ft_putstr_fd("ERROR : PARSING RGB < 0 || RGB > 255\n", 0);
    if (code == 9)
        ft_putstr_fd("ERROR : PARSING MAP OPEN\n", 0);
    if (code == 10)
        ft_putstr_fd("ERROR : PARSING ERROR SPOWN\n", 0);
    if (code == 11)
        ft_putstr_fd("ERROR : UPLOADING TEXTURES FAILS\n", 0);
    if (code <= 8)
        data->err = -1;
    else
        data->err = -2;
}