/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:56:00 by dquitzon          #+#    #+#             */
/*   Updated: 2019/02/25 21:26:57 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return (&((char*)str)[i]);
	return (NULL);
}
