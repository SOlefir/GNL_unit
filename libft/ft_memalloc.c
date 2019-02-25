/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 08:05:17 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/21 20:28:35 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*c;

	c = NULL;
	i = 0;
	if (size == 0)
		return (NULL);
	c = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (c == NULL)
		return (NULL);
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
	return ((void *)c);
}
