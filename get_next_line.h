/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:01:30 by Gkatounk          #+#    #+#             */
/*   Updated: 2020/12/01 11:16:23 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *ptr);
char	*ft_strdup(const char *ptr);
char	*ft_strchr(const char *ptr, int c);
char	*ft_strjoin(char *ptr1, char *ptr2);
char	*ft_substr(char const *ptr, unsigned int start, size_t len);

#endif
