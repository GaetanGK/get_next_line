/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:52:50 by Gkatounk          #+#    #+#             */
/*   Updated: 2020/12/02 11:54:45 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char **str)
{
	char	*buff;
	int		nbytes;
	char	*t;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (*str == NULL)
		*str = ft_strdup("");
	while (!(ft_strchr(*str, '\n')))
	{
		if ((nbytes = read(fd, buff, BUFFER_SIZE)) < 0)
			return (0);
		buff[nbytes] = '\0';
		t = ft_strjoin(*str, buff);
		free(*str);
		*str = t;
		if (nbytes == 0)
			break ;
	}
	free(buff);
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str[1024];
	char			*temp;
	char			*t;

	if (!line || !(str[fd] = ft_read(fd, &str[fd])))
		return (-1);
	if ((temp = ft_strchr(str[fd], '\n')))
	{
		t = str[fd];
		*line = ft_substr(str[fd], 0, temp - str[fd]);
		str[fd] = ft_strdup(str[fd] + (temp - str[fd]) + 1);
		free(t);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}
