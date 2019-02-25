/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:46:59 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/23 23:58:23 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		len;
	char		*str;

	str = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (ft_iswhitespace(s[i]) && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	len = ft_strlen(&s[i]);
	while (ft_iswhitespace(s[len + i - 1]) && (len + i) > 0)
		len--;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
		str[len] = s[len + i];
	return (str);
}
