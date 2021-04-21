/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:00:52 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/18 17:38:04 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_debug(t_data *data)
{
	int i;
	
	i = 0;
	while (data->tab[i])
	{
            printf("tab[%i] == [%s]\n", i, data->tab[i]);
			i++;
	}
	printf("DANS debug  : \n");
    printf(" R : w == %i && h == %i\n", data->w_w, data->w_h);
    printf("path[0] == [%s]\n", data->tex.r_path[0]);
	printf("path[1] == [%s]\n", data->tex.r_path[1]);
	printf("path[2] == [%s]\n", data->tex.r_path[2]);
	printf("path[3] == [%s]\n", data->tex.r_path[3]);
	printf("path[4] == [%s]\n", data->tex.r_path[4]);
	printf(" F && C : f == %lu && c == %lu\n", data->tex.floor, data->tex.ceiling);
	i = 0;
	while (data->maps[i])
	{
		printf("map == [%s]\n", data->maps[i]);
		i++;
	}
	printf("\n ----------- \n");
	printf("dir_eye == [%f]\n", data->cam.dir_eye);
	printf("dir_x == [%f] && dir_y == [%f]\n", data->cam.dir_x, data->cam.dir_y);
	printf("plane_x == [%f] && plane_y == [%f]\n", data->cam.plane_x, data->cam.plane_y);
}

int			close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	clean_up(5, data);
	//system("leaks cub3D");
	return (0);
}

int		loop_hook(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, render_next_frame, data);
	mlx_hook(data->win, 2, 1L << 1, render_next_frame, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	return (0);
}

static int		ft_check_ext(char *str)
{
	int i;
	int fd;
	int errno;

	i = 0;
	errno = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		code_err(errno);
	close(fd);
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (ft_strncmp(str + i, ".cub", 5) == 0)
		return (1);
	else
		return (0);
}

int	brain(int argc, char **argv, t_data *data)
{
	init_data(data);
	pars_brain(argv[1], data);
	if (data->err == 0)
	{	
		get_first_player_pos(data);
		ft_putstr_fd("PARSING : OK\n", 0);
		load_xpm(data);
	}
	else
	{
		ft_putstr_fd("ERROR : PARSING FAIL ==> CLEAN UP\n", 0);
		return (0);
	}	
	if (argv[2] && ft_check_arg(argc, argv[2]) == 1)
		return(2);
	return (1);
}


int				main(int argc, char **argv)
{
	t_data data;
	int		res;

	if (argc > 1 && ft_check_ext(argv[1]) == 1)
	{	
		res = brain(argc, argv, &data);
		if (res == 1)
		{
			ft_putstr_fd("HAVE FUN ;)!\n", 0);
			data.win = mlx_new_window(data.mlx, data.w_w, data.w_h, "HeSayah Cub3D");
			data.img = mlx_new_image(data.mlx, data.w_w, data.w_h);
			data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
			render_next_frame(0, &data);
			loop_hook(&data);
			mlx_loop(data.mlx);
		}
		else if (res == 2)
			save(&data);
	}
	else
		ft_putstr_fd("ERROR : MISSING <file>.cub\n", 0);
	exit(0);
	return (0);
}