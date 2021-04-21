/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:36:49 by hesayah           #+#    #+#             */
/*   Updated: 2021/03/27 15:06:46 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*new;

	if (!str1 || !str2)
		return (NULL);
	new = NULL;
	if (!(new = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		new[i + j] = str2[j];
		j++;
	}
	free((void*)str1);
	new[i + j] = '\0';
	str1 = NULL;
	return (new);
}
