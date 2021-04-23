/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:00:52 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/23 04:53:16 by hedi             ###   ########.fr       */
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
	/*printf("DANS debug  : \n");
    printf(" R : w == %i && h == %i\n", data->w_w, data->w_h);
    printf("path[0] == [%s]\n", data->tex.r_path[0]);
	printf("path[1] == [%s]\n", data->tex.r_path[1]);
	printf("path[2] == [%s]\n", data->tex.r_path[2]);
	printf("path[3] == [%s]\n", data->tex.r_path[3]);
	printf("path[4] == [%s]\n", data->tex.r_path[4]);
	printf(" F && C : f == %lu && c == %lu\n", data->tex.floor, data->tex.ceiling);
	i = 0;
	while (data->map[i])
	{
		printf("map == [%s]\n", data->map[i]);
		i++;
	}
	printf("\n ----------- \n");
	printf("dir_eye == [%f]\n", data->cam.dir_eye);
	printf("dir_x == [%f] && dir_y == [%f]\n", data->cam.dir_x, data->cam.dir_y);
	printf("plane_x == [%f] && plane_y == [%f]\n", data->cam.plane_x, data->cam.plane_y);*/
}

int			close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void		loop_hook(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->w_w, data->w_h, "HeSayah Cub3D");
	data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_hook(data->win, 2, 1L << 0, action_key, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_hook(data->win, 33, 1L << 17, close_window, data);
	mlx_loop(data->mlx); 

}

static int		ft_check_ext(char *str, t_data *data)
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
		exit_error(0, data);
	return (0);
}

int	brain(int argc, char **argv, t_data *data)
{
	init_data(data);
	pars_brain(argv[1], data);
	if (data->err == -1)
	{
		ft_putstr_fd("ERROR : PARSING FAIL ==> CLEAN UP\n", 0);
		return (0);
	}
	if (!(load_xpm(data)))
		return (0);
	if (argv[2] && ft_check_arg(argc, argv[2]) == 1)
		return(2);
	return (1);
}


int				main(int argc, char **argv)
{
	t_data data;
	int		res;

	if (argc > 1 && ft_check_ext(argv[1], &data) == 1)
	{	
		data.mlx = mlx_init();
		res = brain(argc, argv, &data);
		if (res == 1)
			loop_hook(&data);
		else if (res == 2)
			save(&data);
	}
	else
		ft_putstr_fd("ERROR : MISSING <file>.cub\n", 0);
	exit(0);
	return (0);
}