/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:25:31 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/22 19:07:12 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_next_line.h"

int	get_next_line(int fd, char **line)
{
	int x;
	int byte;
	char *buffer;
	static char *save;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);

	if (!save)
		save = ft_strdup("");

	byte = read(fd, buffer, BUFFER_SIZE);
	x = 0;
	while (1)
	{
		if (byte == 0)
			return (0);
		if (byte == -1)
			return (-1);

		buffer[byte] = '\0';
		save = ft_strdup(buffer);
		printf("-> %s\n", save);
		if (save[x] == '\n')
		{
			save[x] = '\0';
			*line = ft_strjoin(*line, save);
			save = ft_strdup(&save[x + 1]);						//ICI
			return(1);
		}
		if (save[x] == '\0')
		{
			if (!*line)
				*line = ft_strdup(save);
			else
				*line = ft_strjoin(*line, save);				//JOIN(SAVE,BUFFER)?
			free(save);
			byte = read(fd, buffer, BUFFER_SIZE);
			x = -1;
		}
		x++;
	}
	return (0);
}

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
	}
	free(line);
	close(fd);
	return (0);
}