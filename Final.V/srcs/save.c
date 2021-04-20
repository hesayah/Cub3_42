/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedi <hedi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:07:39 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/20 02:50:50 by hedi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_arg(int argc, char *str)
{
    if (argc > 3)
    {
        ft_putstr_fd("ERROR : TOO MANY ARGUMENTS\n", 0);
        exit(0);
    }
	if (ft_strncmp(str, "--save", 7) == 0)
		return (1);
	else
	{
		ft_putstr_fd("ERROR : BAD ARGUMENT\n", 0);
		exit(0);
	}
	return (0);
}

void	ft_header_bmp(int fd, t_data *data)
{
  int	tmp;

  write(fd, "BM", 2);
  tmp = 54 + 4 * data->w_w * data->w_h; 
  write(fd, &tmp, 4);
  tmp = 0;
  write(fd, &tmp, 2); 
  write(fd, &tmp, 2);
  tmp = 54;
  write(fd, &tmp, 4);
  tmp = 40;
  write(fd, &tmp, 4);
  write(fd, &data->w_w, 4);
  write(fd, &data->w_h, 4);
  tmp = 1;
  write(fd, &tmp, 2);
  write(fd, &data->bits_per_pixel, 2);
  tmp = 0;
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
}

void    create_save_bmp(int fd, t_data *data)
{
  int x;
  int y;

  
  y = data->w_h - 1;
  while (y >= 0)
  {
    x = 0;
    while (x < data->w_w)
    {
      write(fd, &data->addr[y * data->line_length + x * (data->bits_per_pixel / 8)], 4);
      x++;
    }
    y--;
  }
}

void	save_frame(t_data *data)
{
	double buff[data->w_w];

	action_key(0, data);
	ray_casting(buff, data);
	if (data->srt.hit == 1)
		brain_sprite(data->tex.tex[4], buff,  data);
	draw_map(data);
	draw_player(data);
}


void    save(t_data  *data)
{
	int fd;

  fd = open("save.bmp", O_RDONLY) ;
  if (fd != -1)
    system("rm save.bmp");
	fd = open("save.bmp", O_CREAT | O_WRONLY, 0777);
  data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
  save_frame(data);
  ft_header_bmp(fd, data);
  create_save_bmp(fd, data);
	close(fd);
}