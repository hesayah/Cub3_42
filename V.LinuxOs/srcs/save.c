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



void	header_bmp(int fd, t_data *data)
{
  int	full_size;
  int offset;

  offset = 54;
  full_size = offset + data->w_w * data->w_h * 4;
  write(fd, "BM", 2);
  write(fd, &full_size, 4);
  write(fd, "\0\0\0\0", 4);
  write(fd, &offset, 4);
}

void  header_img(int fd, t_data *data)
{
  int plan;
  int header_img_size;
  
  plan = 1;
  header_img_size = 40;
  write(fd, &header_img_size, 4);
  write(fd, &data->w_w, 4);
  write(fd, &data->w_h, 4);
  write(fd, &plan, 2);
  write(fd, &data->bits_per_pixel, 2);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void    set_img_in_bmp(int fd, t_data *data)
{
  int x;
  int y;
  
  y = data->w_h - 1;
  while (y >= 0)
  {
    x = 0;
    while (x < data->w_w)
    {
      write(fd, &data->addr[y * data->line_length + x *
      (data->bits_per_pixel / 8)], 4);
      x++;
    }
    y--;
  }
}

void    save(t_data  *data)
{
	int fd;

  data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
  save_frame(data);
  fd = open("save.bmp", O_RDONLY) ;
  if (fd != -1)
    system("rm save.bmp");
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_APPEND, 0777);
  header_bmp(fd, data);
  header_img(fd, data);
  set_img_in_bmp(fd, data);
	close(fd);
  mlx_destroy_image(data->mlx, data->img);
  clean_up(data);
}