/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:26:01 by solefir           #+#    #+#             */
/*   Updated: 2019/02/11 17:44:34 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static long int		is_end_str(char *str, size_t count)
{
	int long i;

	i = 0;
	while (i != count || str[i] != '\0' || str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i =* -1;
	return (i);
}

static size_t		*red_and_white(const int fd, size_t BUFF_SIZE, t_list *head)
{
	size_t	i;
	t_list	*temp;
	char	*buf;

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

static void		in_line(t_list	**head, char	**line)
{
	size_t	leng;
	t_list	node;

	leng = 0;
	node = head;
	while (node->next ! = NULL)
		{
			node = node->next;
			leng = leng + node->strl;
		}
	line = ft_strnew(leng - 1); /* ... - 1 for '\n' */
	while (node->next ! = NULL)
		{
			node = node->next;
			line = node->str;
		}
}

int		get_next_line(const int fd, char **line)
{
	size_t	BUFF_SIZE;
	int		i;
	t_list	*head;

	head = NULL;
	red_and_white(fd, BUFF_SIZE, *head), **line);
	in_line(**head, **line)
	return(i);
}

int		main(int ac, char **av)
{
}
