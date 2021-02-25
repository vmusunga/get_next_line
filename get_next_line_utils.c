/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:45:00 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/25 12:07:58 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

void	ft_memzero(void *s)
{
	int i;

	i = 0;
	while (((char*)s)[i])
	{
		((char*)s)[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	if (!(cpy = malloc(sizeof(const char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	//free ((void*)s1);
	return (cpy);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*dest;

	i = 0;
	if ((!s1) || (!s2))
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x])
	{
		dest[i + x] = s2[x];
		x++;
	}
	dest[i + x] = '\0';
	free (s1);
	//free (s2);
	return (dest);
}