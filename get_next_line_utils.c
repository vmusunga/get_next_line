/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:20:53 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/17 16:42:21 by vmusunga         ###   ########.fr       */
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
	while (read(fd, &b, 1) > 0)
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
	//if ((!s1) || (!s2))
	//	return (NULL);
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

int		check_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char*	save_trim(char *save)
{
	int i;
	char *tmp;
	int x;

	i = 0;
	x = 0;
	if(!(tmp = malloc(sizeof(char) * (ft_strlen(save) + 1))))
		return (0);
	while (save[i] != '\n')
		i++;
	i++;
	while(save[i])
		tmp[x++] = save[i++];
	free(save);
	return (tmp);
}

void	ft_clean(char *str)
{
	free(str);
	str = NULL;
}

void	append_till_n(char *src, char *dst, char n)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(dst[x] && dst[x] != n)
		dst[x++] = src[y++];
	return ;
}

char	*append_till_n2(char *src, char n)
{
	int x;
	char *dst;

	x = 0;
	while(src[x] && src[x] != n)
		x++;
	if (!(dst = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	x = 0;
	while(src[x] && src[x] != n)
	{
		dst[x] = src[x];
		x++;
	}
	return (dst);
}