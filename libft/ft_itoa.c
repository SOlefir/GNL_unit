/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:12:32 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/24 00:49:14 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_itoa(int n)
{
	size_t			i;
	char			*str;
	unsigned int	nmb;
	unsigned int	tmp;

	i = 1;
	nmb = (n < 0) ? (n * (-1)) : n;
	if (n < 0)
		i++;
	tmp = nmb;
	while ((tmp / 10) != 0 && ++i)
		tmp = tmp / 10;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
