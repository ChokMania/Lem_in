/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:56:39 by judumay           #+#    #+#             */
/*   Updated: 2019/02/25 13:54:21 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char	*ft_give(int fd, char **s, char *line, char *t)
{
	if (ft_strchr(s[fd], '\n'))
	{
		if (!(line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd])))
			return (0);
		t = s[fd];
		if (!(s[fd] = ft_strsub(t, ft_strchr(t, '\n') - t + 1, ft_strlen(t))))
			return (0);
		free(t);
	}
	else
	{
		if (!(line = ft_strdup(s[fd])))
			return (0);
		ft_strdel(&s[fd]);
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*t;
	static char	*s[2147483648];

	if (BUFF_SIZE < 1 || fd < 0 || !line || (!s[fd] && !(s[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		t = s[fd];
		if (!(s[fd] = ft_strjoin(t, buf)))
			return (-1);
		free(t);
	}
	if (ret == -1 || !(*line = ft_give(fd, s, *line, t)))
		return (-1);
	return ((!s[fd] && ft_strlen(*line) == 0) ? 0 : 1);
}
