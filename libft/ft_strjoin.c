/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:36:18 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 22:11:07 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		k;
	size_t		len;
	char		*join;

	i = -1;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == (size_t)(-1))
		return (NULL);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[k] != '\0')
		join[i++] = s2[k++];
	join[i] = '\0';
	return (join);
}
