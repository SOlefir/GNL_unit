/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:02:08 by solefir           #+#    #+#             */
/*   Updated: 2019/02/22 15:53:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

#define BUFF_SIZE 500

typedef struct		s_gnl
{
	char			*str;
	char			*end;

}					t_gnl;

#endif