/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:53:16 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/21 08:07:16 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../../cub3d.h"

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
size_t	ft_check(char *str);
size_t	ft_checklen(char *str);
char	*ft_res(char *res);
char	*ft_start(char *res, int fd);
char	*ft_res2(int ret, char *res, char *buff);

#endif
