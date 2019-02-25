/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 05:10:27 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 22:29:57 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl(char const *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != 0)
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}
