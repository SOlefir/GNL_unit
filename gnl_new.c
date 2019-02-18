/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:17:10 by solefir           #+#    #+#             */
/*   Updated: 2019/02/18 18:39:07 by solefir          ###   ########.fr       */
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

static t_list		*write_in_line(t_list *head, size_t count, int fd, char **line)
{
	t_list		*temp;
	int			k;

	temp = head;
	k = 0;
	*line = ft_strnew(count);
	while (line = temp   )/*temp->next != NULL*/
		{
			while (k != temp->content_size)
				*line[i++] = (temp->content)[k++];
		}
	return(temp);
}

static int			read_and_write(t_list *head, t_list **storage, const int fd, char **line)
{
	t_list	*temp;
	char	*there;
	char	*buf[BUFF_SIZE];
	int		i;
	int		count;

	temp = head;
	there = NULL;
	count = 1;
	while (i = read(fd, &buf, BUFF_SIZE) > 0 || there == NULL)
	{
		if (head == NULL)
			{
				head = ft_lstnew(&buf, (size_t)i);
				temp = head;
			}
		else
			{
				temp->next = ft_lstnew(&buf, (size_t)i);
				temp = temp->next;
				count =* i;
			}
		there = ft_strchr(*buf, '\n');
	}
	storage->next = write_in_line(head, count, fd, &line);
	return (i);
}


int		get_next_line(const int fd, char **line)
{
	t_list			*buffer;
	static	t_list	*storage = NULL; 

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	buffer = find_fd(storage, fd);
	return (read_and_write(buffer, &storage, fd)));
}

/* я думаю, что решение должно быть простым в несколько крупных шагов
	1. считать и записать в листы (подсчитывая их)
	2. из листов записать в лайн удаляя их до последнего
	3. сохранить в структуру фд и последний лист */