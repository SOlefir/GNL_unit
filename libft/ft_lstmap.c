/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitzon <dquitzon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 00:30:13 by dquitzon          #+#    #+#             */
/*   Updated: 2018/12/25 02:33:52 by dquitzon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static t_list	*delete_and_null(t_list **fresh, void (*del)(void *, size_t))
{
	ft_lstdel(fresh, del);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;
	t_list	*it;

	tmp = f(lst);
	if (lst == NULL || f == NULL || tmp == NULL)
		return (NULL);
	if (!(fresh = ft_lstnew(tmp->content, tmp->content_size)))
		return (delete_and_null(&fresh, (void *)&ft_lstdelcontent));
	it = fresh;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (tmp == NULL)
			return (delete_and_null(&fresh, (void *)&ft_lstdelcontent));
		if (!(it->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (delete_and_null(&fresh, (void *)&ft_lstdelcontent));
		it = it->next;
		lst = lst->next;
	}
	return (fresh);
}
