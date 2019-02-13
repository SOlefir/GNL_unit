/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:26:01 by solefir           #+#    #+#             */
/*   Updated: 2019/02/13 14:27:19 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t		is_end_str(char *str, size_t count)
{
	size_t i;

	i = 0;
	while (i != count || str[i] != '\0' || str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i = -1;
	return (i);
}

static size_t		red_and_white(const int fd, size_t BUFF_SIZE, t_partstr *head)
{
	size_t			i;
	size_t			there;
	t_partstr		*temp;
	char			*buf;

	there = 1;
	while (i = read(fd, *buf, BUFF_SIZE) > 0 || there > 0)
	{
		if (head == NULL)
			{
				head = ft_lstnew(*buf, i);
				temp = head;
			}
		else
		{
			temp->next = ft_lstnew(*buf, i);
			temp = temp->next;
		}
		there = is_end_str(*buf, i);
	}
	return (i);
}

static void		in_line(t_partstr *head, char **line)
{
	size_t		leng;
	t_partstr	*node;
	t_partstr	*temp;

	leng = 0;
	node = head;
	while (node->next != NULL)
		{
			leng = leng + node->strl;
			node = node->next;
		}
	line = ft_strnew(leng);
	temp = node->next;
	while (node->next != NULL)
		{
			line = temp->str;
			temp = temp->next;
			ft_lstdelone(node)
		}
}

int		get_next_line(const int fd, char **line)
{
	size_t		BUFF_SIZE;
	int			i;
	t_partstr	*head;

	head = NULL;
	red_and_white(fd, BUFF_SIZE, head);
	in_line(head, line);
	return(i);
}

int		main()
{
	char *str;

	str = ft_strnew(3);
	get_next_line(0, &str);
	return (0);
	укенг
}
