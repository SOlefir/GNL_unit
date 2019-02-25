/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:04:10 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 22:32:55 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*c;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL || f == NULL || c == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		c[i] = f(s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
