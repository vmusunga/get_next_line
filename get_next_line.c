/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/02 14:40:32 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int i;
	int x;

	char *buffer;

	if (ft_error(fd) < 0)
		return (-1);

	fd = open(FILE, O_RDONLY);

	//printf("size: %d\n", ft_line_size(fd));
	if (!(*line = malloc(sizeof(char) * ft_line_size(fd))))
		return (0);
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);

	i = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
		{
			*line[i++] = buffer[x++];
			printf("%s\n", *line);
		}
		if (buffer[x] == '\n')
			return (1);
	}

	*line[i] = '\0';
	//printf("line : %s\n", line);
	//printf("buffer : %s\n", buffer);
	close(fd);
	return (0);
	free(line);
	free(buffer);
}

int		main(int argc, char *argv[])
{
	int fd;
	char *res;
	char *line[100];

	argc = 2;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	res = *line;
	printf("%d\n", get_next_line(fd, line));
	printf("%s\n",res);
	return (0);
}