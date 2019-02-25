/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_masmemdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:32:59 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/24 20:17:29 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_masmemdel(void ***mas, size_t count)
{
	size_t	i;

	i = 0;
	if (mas == NULL || *mas == NULL)
		return ;
	while (i < count)
	{
		if ((*mas)[i] != NULL)
			free((*mas)[i]);
		(*mas)[i] = NULL;
		i++;
	}
	free(*mas);
	*mas = NULL;
}
