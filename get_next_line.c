/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:39:42 by Gkatounk          #+#    #+#             */
/*   Updated: 2020/12/01 11:13:05 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *ptr)
{
	char		*buff;
	int			len;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (ptr == NULL)
		ptr = ft_strdup("");
	while (!(ft_strchr(ptr, '\n')))
	{
		if ((len = read(fd, buff, BUFFER_SIZE)) < 0)
			return (0);
		buff[len] = '\0';
		temp = ft_strjoin(ptr, buff);
		free(ptr);
		ptr = temp;
		if (len == 0)
			break ;
	}
	free(buff);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*temp;
	char		*ptr;

	if (!line || !(str = ft_read(fd, str)))
		return (-1);
	if ((temp = ft_strchr(str, '\n')))
	{
		ptr = str;
		*line = ft_substr(str, 0, temp - str);
		str = ft_strdup(str + (temp - str) + 1);
		free(ptr);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
}
