/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:17:38 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 22:53:54 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	g;
	size_t	k;
	size_t	res;

	i = ft_strlen(dst);
	g = ft_strlen(src);
	k = 0;
	if (i > size)
		return (size + g);
	res = i + g;
	while (i < (size - 1) && src[k] != '\0')
	{
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (res);
}
