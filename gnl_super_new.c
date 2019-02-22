#include "./get_next_line.h"
#include <stdio.h>

int		read_in_buf(const int fd, t_gnl *gnl)
{
	char	buf[BUFF_SIZE];
	int		i;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0 && gnl->end == NULL)
	{
		 if (gnl->str == NULL)
			gnl->str = ft_strdup(buf);
		else
			gnl->str = ft_strjoin(gnl->str, buf);
		gnl->end = ft_strchr(buf, '\n');
	}
	printf("%s\n", gnl->str);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				i;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	i = read_in_buf(fd, gnl);
	return (i);		
}

int		main()
{
	int		fd;
	int		i;
	char	*line;

	/*fd = 0;*/
	if ((fd = open("readme.txt", O_RDWR)) < 0)
		printf("Cannot open file.\n");
	i = get_next_line(fd, &line);
	printf("%d %s", i, "bytes\n");
	return (0);
}