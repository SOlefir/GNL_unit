/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:39:02 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/25 04:55:44 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * i);
	if (dup == NULL)
		return (NULL);
	while (i-- > 0)
	{
		dup[i] = s[i];
	}
	return (dup);
}
