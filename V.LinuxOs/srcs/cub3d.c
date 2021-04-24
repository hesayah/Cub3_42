/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:00:52 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 11:21:37 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	clean_up(2, data);
	exit(0);
	return (0);
}

void		loop_hook(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->w_w,
	data->w_h, "HeSayah Cub3D");
	data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
	mlx_hook(data->win, 2, 1L << 0, action_key, data);
	mlx_hook(data->win, 33, 1L << 17, close_window, data);
	//mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

static int	ft_check_ext(char *str, t_data *data)
{
	int	i;
	int	fd;
	char *line;
	int	errno;

	errno = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		code_err(errno);
		return (0);
	}
	i = get_next_line(fd, &line);
	free(line);
	if (!i)
		return (0);
	close(fd);
	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (ft_strncmp(str + i, ".cub", 5) == 0)
		return (1);
	exit_error(0, data);
	return (0);
}

int			brain(int argc, char **argv, t_data *data)
{
	init_data(data);
	pars_brain(argv[1], data);
	if (!(load_xpm(data)))
		return (clean_up(2, data));
	if (argv[2] && ft_check_arg(argc, argv[2]) == 1)
		return (2);
	return (1);
}

int			main(int argc, char **argv)
{
	t_data	data;
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
