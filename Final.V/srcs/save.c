/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:07:39 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/18 18:11:28 by hesayah          ###   ########.fr       */
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

  tmp = 14 + 40 + 4 * data->w_w * data->w_h; //La taille totale du fichier en octets (codée sur 4 octets)
  write(fd, &tmp, 4);
  tmp = 0;
  write(fd, &tmp, 2); 
  write(fd, &tmp, 2); 
  tmp = 54;
  write(fd, &tmp, 4);
  tmp = 40;
  write(fd, &tmp, 4);
  write(fd, &data->w_w, 4); //La largeur de l'image (sur 4 octets), c'est-à-dire le nombre de pixels horizontalement (en anglais width)
  write(fd, &data->w_h, 4); //La hauteur de l'image (sur 4 octets), c'est-à-dire le nombre de pixels verticalement (en anglais height)
  tmp = 1;
  write(fd, &tmp, 2); //Le nombre de plans (sur 2 octets). Cette valeur vaut toujours 1
  write(fd, &data->bits_per_pixel, 2); //La profondeur de codage de la couleur(sur 2 octets), c'est-à-dire le nombre de bits utilisés 
  		    		           //pour coder la couleur. Cette valeur peut-être égale à 1, 4, 8, 16, 24 ou 32
  tmp = 0;
  write(fd, &tmp, 4); //La méthode de compression (sur 4 octets). Cette valeur vaut 0 lorsque l'image n'est pas compressée
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
  write(fd, &tmp, 4);
}

void    create_img_bmp(int fd, int *img, t_data *data)
{
  int x;
  int y;

  
  y = data->w_h;
  while (y > 0)
  {
    x = 0;
    while (x < data->w_w)
    {
        data->srt.color = img[data->w_h * y + x];
        write(fd, &data->srt.color, 16);
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
	FILE *save_img;

	save_img = NULL;
    data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
    save_frame(data);
	fopen("../save.bmp", "w");
    ft_header_bmp(save_img, data);
    create_img_bmp(save_img, data->img, data);
	fclose(save_img);
}