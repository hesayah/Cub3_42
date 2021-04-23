/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:38:36 by hesayah           #+#    #+#             */
/*   Updated: 2021/04/18 15:26:46 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab)
{
	int i;

	i = 0;
	if (!(tab))
		return ;
	while (tab[i] != NULL)
		i++;
	while (i >= 0)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i--;
	}
	free(tab);
}