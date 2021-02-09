/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/08 15:52:43 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	get_next_line(int fd, char **line)
{
	int i;
	static int x;
	int y;
	int j;
	int a;
	static int bytes;
	char *buffer;
	static char *save;

	y = 0;
	if (ft_error(fd) < 0)
		return (-1);
	//printf("size:\t%d\n", ft_line_size(fd));
	if (!(*line = malloc(sizeof(char) * (ft_line_size(fd) + 1))))
		return (3);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	
	i = 0;
	j = 0;
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		printf("bytes : %d\n", bytes);
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
		{
			line[j][i++] = buffer[x++];
			//printf("buffer : %s\n", buffer);
		}
		printf("buffer :\t%s\n", buffer);
		if (buffer[x] == '\n')
		{
			y = 1;
			break;
		}
	}
	x++;
	a = 0;
	if (!(save = (char*)malloc(sizeof(char) * (bytes - x))))
			return (3);
	while (bytes - x && buffer[x])
	{
		save[a++] = buffer[x++];
	}
	printf("save :%s\n", save);
	line[j][i] = '\0';
	return (y);
}
*/

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
	while (buffer[i])
		save[a++] = buffer[i++];
	save[i] = '\0';
	return (save);
}

void	clear_save(char *save)
{
	free(save);
	save = NULL;
}

int	get_next_line(int fd, char **line)
{
	
	char *save2;
	
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	read(fd, buffer, BUFFER_SIZE);
	while (save[i] && save[i] != '\n')
	{
		line[x][y++] = save[i++];
	}
	i++;
	j = 0;
	while (save[i])
	{
		save2[j++] = save[i++]; 
	}
}

int		main()
{
	int fd;
	int x;
	int y;
	char *line;

	y = 0;
	fd = open(FILE, O_RDONLY);
	while (y < 10)
	{
		x = get_next_line(fd, &line);
		y++;
		printf("%d | *line :\t%s\n", x, line);
	}
	close(fd);
	return (0);
}