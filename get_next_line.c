/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/15 16:30:09 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int i;
	int x;
	int y;
	char *buffer;
	static char *save;
	char *part1;
	char *part2;
	
	y = 0;
	i = 0;

	if (!(part1 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(part2 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);

	if (save != NULL)
	{
		save = clear_save(save);
		while (save[i] && save[i] != '\n')
		{
			part1[i] = save[i];
			i++;
		}
	//printf("saveclear -> %s\n", save);
	}
	if (ft_error(fd) < 0)
		return (-1);

	if (!(*line = malloc(sizeof(char) * (ft_line_size(fd) + 1))))
		return (3);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);


	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
		{
			part2[x] = buffer[x];
			x++;
		}
		if (buffer[x] == '\n')
		{
			y = 1;
			break;
		}
	}

	if (!save)
		save = ft_strdup(buffer);
	else
		save = ft_strjoin(save, buffer);

	//printf("savejoin -> %s\n", save);
	//printf("BUFF |	:	%s\n", buffer);
	//printf("\nS | save :\t%s\n", save);
	*line = ft_strjoin(part1, part2);
	return (y);
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