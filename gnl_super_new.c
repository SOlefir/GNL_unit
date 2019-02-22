#include "./get_next_line.h"
#include <stdio.h>

//void	in_line()

int		read_in_buf(const int fd, t_gnl	*gnl)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		i;
	int		count;

	count = 0;
	// if (gnl->end != NULL)
	// 	gnl->str = gnl->end + 1; (это в фнкц in_line)
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
	gnl->end = ft_strsub(gnl->str, (gnl->end - gnl->str), count); 
	gnl->fd = fd;
	printf("%s\n", gnl->str);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*temp;
	int				i;

	temp = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	//temp = find_fd(gnl); 
	///in_line(temp, line);
	i = read_in_buf(fd, temp);
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