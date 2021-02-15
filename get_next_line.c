/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/15 13:19:48 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int i;
	int x;
	int y;
	int j;
	int a;
	int bytes;
	char *buffer;
	static char *save;
	static char *new_save;
	char *part1;
	char *part2;

	if (!(part1 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(part2 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);

	y = 0;
	i = 0;
	//printf("saveb	:	%s\n", save);
	if (save != NULL)
	{
		new_save = save_buffer(save);
		while (save [i] && save[i] != '\n')
		{
			part1[i] = save[i];
			
			i++;
		}
	}
	//printf("PART1 %s\n",part1);
	//printf("NEW_SAVE %s\n",new_save);
	clear_save(save);

	if (ft_error(fd) < 0)
		return (-1);

	//printf("size:\t%d\n", ft_line_size(fd));
	if (!(*line = malloc(sizeof(char) * (ft_line_size(fd) + 1))))
		return (3);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(save = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(new_save = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);

	
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
			part2[i++] = buffer[x++];
		if (buffer[x] == '\n')
		{
			y = 1;
			break;
		}
	}
	//printf("B | buffer :\t%s\n", buffer);
	save = save_buffer(buffer);
	//ft_memccpy(save, buffer, '\n', BUFFER_SIZE);
	//ft_memccpy(new_save, ft_memccpy(save, buffer, '\n', BUFFER_SIZE), '\n', BUFFER_SIZE);
	printf("\nS | save :\t%s\n", save);
	//printf("S | new :\t%s\n", new_save);
	*line = ft_strjoin(part1, part2);
	return (y);
}

/*
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
*/

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
		printf("%d | *line :\t%s\n\n", phrase, line);
		phrase++;
	}
	close(fd);
	return (0);
}