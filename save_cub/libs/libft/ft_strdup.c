/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:19:21 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/18 16:49:25 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (str && str[i])
		i++;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	ft_bzero(dest, i);
	i = 0;
	while (str && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
