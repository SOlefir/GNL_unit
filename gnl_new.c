/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:17:10 by solefir           #+#    #+#             */
/*   Updated: 2019/02/17 20:45:18 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static t_list		*find_fd(t_list *head, int fd)
{
	t_list	*temp;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (temp->content_size != fd)
		temp = temp->next;
	return (temp);
}

static t_list		*write_in_line(t_list *head, char **line, char last_str)
{
	t_list	*temp;
	size_t		i;
	int			k;

	temp = head;
	i = 0;
	while (temp->next != NULL)
		{
			i++;
			temp = temp->next;
		}
	*line = ft_strnew(i);
	while (k = 0 || temp->next != NULL)
		{
			while (k != temp->content_size)
				*line[i++] = (temp->content)[k++];
			free (head->content);
			free (head->content_size);
			temp = temp->next;
			head = temp;
		}
	return(temp);
}

static int			read_and_write(t_list *head, t_list **storage, const int fd)
{
	t_list	*temp;
	char	*there;
	int		i;

	temp = head;
	there = NULL;
	while (i = read(fd, *buf, BUFF_SIZE) > 0 || there == NULL)
	{
		if (head == NULL)
			{
				head = ft_lstnew(*buf, (size_t)i);
				temp = head;
			}
		else
			{
				temp->next = ft_lstnew(*buf, (size_t)i);
				temp = temp->next;
			}
		there = ft_strchr(*buf, '\n');
	}
	storage->next = write_in_line(head, &line, there, fd);
	return (i);
}


int		get_next_line(const int fd, char **line)
{
	t_list			*buffer; /* hand */
	static	t_list	*storage = NULL; /* cellar */

	if (fd < 0 || !line)
		return (-1);
	buffer = find_fd(storage, fd);
	/* сюда засунуть инициализацию сторедж, шоб записывать лист со строкой и фд */
	return (read_and_write(buffer, &storage, fd) < 0));
}