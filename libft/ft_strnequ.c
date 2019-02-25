/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:29:52 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/25 03:14:51 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
