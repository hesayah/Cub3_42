/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:12:27 by hesayah           #+#    #+#             */
/*   Updated: 2021/01/07 12:01:30 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*content;

	if (!lst)
		return (0);
	i = 1;
	content = lst;
	while (content->next != NULL)
	{
		content = content->next;
		i++;
	}
	return (i);
}
