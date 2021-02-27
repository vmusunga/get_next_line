/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:25:31 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/27 15:51:29 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_free_one(char **s1, int x)
{
	free(*s1);
	*s1 = NULL;
	return (x);
}

static char	*save_trim(char *save, int x)
{
	int		i;
	char	*new;
	int		new_len;

	i = 0;
	x = x + 1;
	new_len = (ft_strlen(save) - x);
	if (!(new = malloc(sizeof(char) * (new_len + 1))))
		return (NULL);
	while (save[x])
		new[i++] = save[x++];
	new[i] = '\0';
	free(save);
	save = NULL;
	return (new);
}

static int	line_saver(char **save, char **line, int fd)
{
	char	*buffer;
	int		byte;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_free_one(save, -1));
	byte = read(fd, buffer, BUFFER_SIZE);
	if (byte == 0)
	{
		*line = ft_strdup(*save);
		return (ft_free_return(save, &buffer, 0));
	}
	if (byte == -1)
		return (ft_free_return(save, &buffer, -1));
	buffer[byte] = '\0';
	if (!(*save = ft_strjoin(*save, buffer)))
		return (ft_free_return(save, &buffer, -1));
	return (byte);
}

static int	line_saver2(char **save, char **line, int x, int fd)
{
	if (!(*line = ft_strdup(*save)))
		return (ft_free_one(&save[fd], -1));
	if (!(*save = save_trim(*save, x)))
		return (ft_free_one(&save[fd], -1));
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			x;
	int			byte;
	static char	*save[OPEN_MAX];

	if (fd < (x = 0) || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!save[fd])
	{
		if (!(save[fd] = ft_strdup("")))
			return (-1);
	}
	while (1)
	{
		if (save[fd][x] == '\n')
			return (line_saver2(&save[fd], line, x, fd));
		if (save[fd][x] == '\0')
		{
			if ((byte = line_saver(&save[fd], line, fd)) == 0 || byte == -1)
				return (byte);
			x = -1;
		}
		x++;
	}
}
