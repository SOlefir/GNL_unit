/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_super_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:43:57 by solefir           #+#    #+#             */
/*   Updated: 2019/02/25 19:02:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
/*#include <stdio.h>*/

static int		in_line(t_gnl *node, char **line)
{
	int		i;

	if (node->str == NULL)
		return (0);
	i = node->end != NULL ? node->end - node->str : ft_strlen(node->str);
	if (!(*line = (char *)malloc(i + 1)))
		return (-1);
	ft_strncpy(*line, node->str, i);
	(*line)[i] = '\0';
	if (node->end != NULL)
		node->end = ft_strsub(node->str, i + 1, node->leng - i);
	free(node->str);
	node->leng -= (i + 1);
	node->str = node->end;
	return (1);
}

static void		read_in_buf(const int fd, t_gnl *gnl, int *bytes)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		i;

	while (gnl->end == NULL && (*bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*bytes] = '\0';
		if (gnl->str == NULL)
			gnl->str = ft_strdup(buf);
		else
		{
			temp = gnl->str;
			gnl->str = ft_strjoin(gnl->str, buf);
			free(temp);
		}
		gnl->end = ft_strchr(gnl->str, '\n');
		gnl->leng += *bytes;
	}
}

static t_gnl	*find_fd(t_gnl *head, int fd)
{
	while (head != NULL && head->fd != fd)
		head = head->next;
	return (head);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*temp;
	int				i;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!(temp = find_fd(gnl, fd)))
	{
		if (!(temp = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
			return (-1);
		temp->next = gnl;
		gnl = temp;
		temp->fd = fd;
	}
	//printf("\n[fd:%d]", temp->fd);
	if (temp->str != NULL && (temp->end = ft_strchr(gnl->str, '\n')))
		return (in_line(temp, line));
	read_in_buf(fd, temp, &i);
	return (in_line(temp, line));
}

/*int		main()
{
	int		fd, fd2, fd3;
	int		i;
	char	*line;

	fd = 0;
	fd2 = open("okay.c", O_RDWR);
	fd3 = open("readme.txt", O_RDWR);
	//
	i = get_next_line(fd2, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	i = get_next_line(fd3, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	i = get_next_line(fd2, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	//
	i = get_next_line(fd3, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	i = get_next_line(fd2, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	i = get_next_line(fd3, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	i = get_next_line(fd3, &line);
	printf("\n[gnl:%d] \n[line:%s]", i, line);
	//
	return (0);
}*/
