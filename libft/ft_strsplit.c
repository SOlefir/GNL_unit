/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:34:19 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/24 15:53:48 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t			i;
	size_t			count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_sw(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			k;
	char			**fresh;

	i = 0;
	if (!(k = 0) && s == NULL)
		return (NULL);
	if (!(fresh = (char **)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (ft_wordcount(s, c) > 0 && s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(fresh[k++] = ft_strsub(s, (unsigned int)i, ft_sw(&s[i], c))))
			{
				ft_masmemdel((void ***)(&fresh), k - 1);
				return (NULL);
			}
			i = i + ft_sw(&s[i], c);
		}
		else
			i++;
	}
	fresh[k] = NULL;
	return (fresh);
}
