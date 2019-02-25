/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:58:29 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 22:32:58 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
