/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:03:52 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/22 16:19:49 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char *buf;

	if (size == (size_t)(-1))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	ft_bzero((void *)buf, (size + 1));
	return (buf);
}
