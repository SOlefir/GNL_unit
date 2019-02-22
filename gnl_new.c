/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:17:10 by solefir           #+#    #+#             */
/*   Updated: 2019/02/20 17:01:17 by solefir          ###   ########.fr       */
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

t_list				*del_node(t_list *head)
{
	t_list	*temp;

	temp = *head; /* удалить 1 node, зафришить. если есть знак "конец строки"а, то удалить контент до этого знака включительно и вернуть этот лист */
	free(head);
}

static t_list		*write_in_line(t_list *head, size_t count, int fd, char **line)
{
	t_list		*temp;
	int			k;

	temp = head;
	k = 0;
	*line = ft_strnew(count);
	while ((temp->content)[k] != '\n')
		{
			k = 0;
			while (k != temp->content_size)
				*line[i++] = (temp->content)[k++];
			temp = temp->next;
			head = del_node(head);
		}
	return(head);
}

static int			read_and_write(t_list *head, char **buf, const int fd, int	*count)
{
	t_list	*temp;
	char	*there;
	int		i;

	temp = head;
	there = NULL;
	while (i = read(fd, &buf, BUFF_SIZE) > 0 || there == NULL)
	{
		if (head == NULL)
			{
				head = ft_lstnew(&buf, (size_t)fd);
				temp = head;
			}
		else
			{
				temp->next = ft_lstnew(&buf, (size_t)fd);
				temp = temp->next;
				*count =+ i;
			}
		there = ft_strchr(buf, '\n');
		*count = *count - (i - (*buf + *there)); /*это попытка отнять из каунта \н, по которому я буду малочить память в лайн,*/
	}
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	t_list			*buffer;
	t_list			*temp;
	static t_list	*storage = NULL;
	int				i;
	size_t			*count[1]; /*так вообще можно? это чтобы считать строки когда я их создаю*/
	char			*buf[BUFF_SIZE];

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	buffer = find_fd(storage, fd); /* ищу фд в статическом списке и записываю в голову буфера */
	i = read_and_write(buffer, &buf, fd, &count) != 0;/*читаю из фд и пишу в стр ноды и фд*/
	temp = storege
	while(temp->next != NULL || temp->content_size != fd) /* нужно дойти до конца списка, чтобы новый записать */
		temp = storage->next;
	temp = write_in_line(buffer, *count, fd, &line);/*записываю из листов в строку, удаляю листы до того, в котором есть '\n' - его записываю в соредж*/
	return (i);
}

/* мб уйти от записи фд в листы, к структуре. то есть сохранять нужные мне листы (с куском строки) в массив поинтеров */