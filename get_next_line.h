/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:02:08 by solefir           #+#    #+#             */
/*   Updated: 2019/02/08 18:05:40 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#define BUFF_SIZE 32
{
	static size_t	BUFF_SIZE;
	BUFF_SIZE = 32;
}


typedef struct		s_list
{
	char*			str;
	size_t			strl;
	struct s_list	*next;
}					t_list;

#endif