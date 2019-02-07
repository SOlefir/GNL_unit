/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:26:01 by solefir           #+#    #+#             */
/*   Updated: 2019/02/07 20:04:12 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "../libft/libft.h"

static size_t		is_end_str(char *str)
{
	size_t i;

	i = 0;
	while (i != BUFF_SIZE)
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	return (-1)
}

int		get_next_line(const int fd, char **line)
{
	size_t	there;

	while (read(fd, t_buf->str, BUFF_SIZE) == BUFF_SIZE && is_end_str(t_buf->str) != 0);

}

int		main(int ac, char **av)
{
	size_t	i;
	int		fd;
	char**	line;
	
	i = 1;
	if(fd = open(av[i], O_RDWR) > 0)
	{
		get_next_line(fd, &line);
		ft_putstr(*line);
		i++;
	}
	return(0);
}
