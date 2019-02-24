#include "./get_next_line.h"
#include <stdio.h>

//void	in_line()

	// if (gnl->end != NULL)
	// 	gnl->str = gnl->end + 1;

t_gnl	*find_fd(t_gnl	*head, int fd)
{
	while (head != NULL && head->fd != fd)
		head = head->next;
	return (head);
}
int		read_in_buf(const int fd, t_gnl	*gnl)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		i;
	int		count;

	count = 0;
	gnl->end = NULL;
	while (gnl->end == NULL && (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (gnl->str == NULL)
			gnl->str = ft_strdup(buf);
		else
		{
			temp = gnl->str;
			gnl->str = ft_strjoin(gnl->str, buf);
			free(temp);
		}
		gnl->end = ft_strchr(gnl->str, '\n');
		count += i;
	}
	i = gnl->end - gnl->str;
	gnl->end = ft_strsub(gnl->str, i + 1, count - i);
	gnl->fd = fd;
	printf("[%s]\n[%s]\n", gnl->str, gnl->end);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*temp;
	int				i;

	if (!(temp = find_fd(gnl, fd)))
	{	
		if (!(temp = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
			{
				printf("malloc_error_temp\n");
				return (-1);
			}
		temp->next = gnl;
		gnl = temp;
		temp->fd = fd; 
	}
	i = read_in_buf(fd, temp);
	// if (!(temp = (t_gnl*)malloc(sizeof(t_gnl))))
	// 	{
	// 		printf("malloc_error2\n");
	// 		return (-1);
	// 	}
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1); 
	//in_line(temp, line);
	return (i);		
}

int		main()
{
	int		fd;
	int		i;
	char	*line;

	/*fd = 0;*/
	if ((fd = open("okay.c", O_RDWR)) < 0)
		printf("Cannot open file.\n");
	i = get_next_line(fd, &line);
	printf("%d %s", i, "bytes\n");
	return (0);
}