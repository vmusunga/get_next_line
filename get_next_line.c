/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:25:31 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/25 15:38:17 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_trim(char *save, int x)
{
	int		i;
	char	*new;
	int		new_len;

	i = 0;
	x = x + 1;
	new_len = (ft_strlen(save) - x);
	if (!(new = malloc(sizeof(char)*(new_len + 1))))
		return (NULL);
	while (save[x])
		new[i++] = save[x++];
	new[i] = '\0';
	free(save);
	save =NULL;
	return (new);
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
	byte = 1;
	while (1)
	{
		if (save[x] == '\n')
		{
			*line = ft_strdup(save);
			save = save_trim(save, x);
			return (1);								//pete un cable if free
		}
		if (save[x] == '\0')
		{
			if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (free_error(&save, &buffer, -1, 1, 0));						//free save
			byte = read(fd, buffer, BUFFER_SIZE);
			if (byte == 0)
			{
				*line = ft_strdup(save);
				return (free_error(&save, &buffer, 0, 1, 1));					//free save && buffer
			}
			if (byte == -1)
				return (free_error(&save, &buffer, -1, 1, 1));				//free save && buffer
			buffer[byte] = '\0';
			save = ft_strjoin(save, buffer);
			x = -1;
		}
		x++;
	}
	return (free_error(&save, &buffer, 0, 1, 1));
}

/*
int		main()
{
	int fd;
	int x;
	int y;
	int phrase;
	char *line;

	phrase = 1;
	y = 0;
	fd = open(FILE, O_RDONLY);
	while (y < 5)
	{
		x = get_next_line(fd, &line);
		y++;
		printf("%d - %d | *line :\t%s\n\n", phrase, x, line);
		phrase++;
		free(line);
	}

	close(fd);
	return (0);
}*/