/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:26:06 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/07 15:55:41 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# define BUFF_SIZE 4096

typedef struct	s_fd
{
	int			fd;
	char		*data;
	char		*offset;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
