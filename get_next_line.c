/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:25:31 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/26 16:06:31 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free_one(char **s1, int x)
{
	free(*s1);
	*s1 = NULL;
	return (x);
}

char	*save_trim(char *save, int x)
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

int		line_saver(char *save, int x, char **line)
{
	*line = ft_strdup(save);
	save = save_trim(save, x);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			x;
	int			byte;
	char		*buffer;
	static char	*save;

	if (!save)
		save = ft_strdup("");
	x = 0;
	while (1)
	{
		if (save[x] == '\n')
		{
			*line = ft_strdup(save);
			save = save_trim(save, x);
			return (1);
		}
		if (save[x] == '\0')
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (ft_free_one(&save, -1));
			byte = read(fd, buffer, BUFFER_SIZE);
			if (byte == 0)
			{
				*line = ft_strdup(save);
				return (ft_free_return(&save, &buffer, 0));
			}
			if (byte == -1)
				return (ft_free_return(&save, &buffer, -1));
			buffer[byte] = '\0';
			save = ft_strjoin(save, buffer);
			x = -1;
		}
		x++;
	}
}
