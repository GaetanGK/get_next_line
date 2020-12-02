/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:58:33 by Gkatounk          #+#    #+#             */
/*   Updated: 2020/11/30 16:04:40 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *ptr)
{
	char	*str;
	char	*res;
	int		i;

	str = (char *)ptr;
	if ((res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))) == 0)
		return (0);
	if (!str)
	{
		*res = '\0';
		return (res);
	}
	i = 0;
	while (*str)
	{
		res[i] = *str;
		str++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *ptr, int c)
{
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return ((char *)ptr);
	return (0);
}

char	*ft_strjoin(char *ptr1, char *ptr2)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	len;

	i = 0;
	j = 0;
	if (!ptr1 || !ptr2)
		return (NULL);
	len = ft_strlen(ptr1) + ft_strlen(ptr2);
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (ptr1[i] != '\0')
	{
		temp[i] = ptr1[i];
		i++;
	}
	while (ptr2[j] != '\0')
		temp[i++] = ptr2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *ptr, unsigned int start, size_t len)
{
	char	*ss;
	char	*sub;
	int		i;

	if (ptr && start > ft_strlen(ptr))
		len = 0;
	ss = (char *)ptr;
	if (ss)
	{
		if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == 0)
			return (0);
		i = 0;
		while (len--)
			sub[i++] = ss[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}
