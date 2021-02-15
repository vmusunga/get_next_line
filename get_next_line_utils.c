/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:20:53 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/15 16:58:29 by vmusunga         ###   ########.fr       */
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

int	ft_line_size(int fd)
{
	int i;
	char b;

	i = 0;
	fd = open(FILE, O_RDONLY);
	while ((read(fd, &b, 1) > 0))
	{
		if (b == '\n' || b == '\0')
			break;
		i++;
	}
	//close(fd);
	return (i);
}

int	ft_error(int fd)
{
	if (fd == -1)
		return (-1);
	return (1);
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
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
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
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] != ((unsigned char)c))
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		else
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}

char *save_buffer(char *buffer)
{
	int i;
	int a;
	char *save;
	
	a = 0;
	i = 0;
	if (!(save = malloc(sizeof(char) * (BUFFER_SIZE))))
		return (0);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	i++;
	while (buffer[i])
		save[a++] = buffer[i++];
	save[a] = '\0';
	return (save);
}

char*	save_trim(char *save)
{
	int i;
	char *tmp;
	int x;

	i = 0;
	x = 0;
	tmp = malloc(sizeof(char) * 100);
	while (save[i] != '\n')
		i++;
	i++;
	while(save[i])
		tmp[x++] = save[i++];
	free(save);
	return (tmp);
}

int		check_n(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
