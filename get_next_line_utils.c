/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:45:00 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/25 15:47:25 by vmusunga         ###   ########.fr       */
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

int free_error(char **s1, char **s2, int x, int a, int b)
{
	if (a == 1)
	{
		free (*s1);
		*s1 = NULL;
	}
	if (b == 1)
	{
		free (*s2);
		*s2 = NULL;
	}
	return(x);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(cpy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
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
	s1 = NULL;
	free (s2);
	s2 = NULL;
	return (dest);
}