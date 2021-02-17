/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/17 13:55:13 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int i;
	int j;
	int x;
	int y;
	int a;
	int byte;
	char *buffer;
	static char *save;
	char *part1;
	char *part2;
	
	y = 0;
	i = 0;
	a = 0;

	if (ft_error(fd) < 0)
		return (-1);
	printf("1----%s\n", part1);
	if (!(part1 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(part2 = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	if (!(*line = malloc(sizeof(char) * (ft_line_size(fd) + 1))))
		return (3);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (3);
	printf("2----%s\n", part1);
	if (save != NULL)
	{
		save = save_trim(save);
		//append_till_n(save, part1, '\n');
		//part1 = append_till_n2(save, '\n');
		while (save[i] && save[i] != '\n')
		{
			part1[a++] = save[i++];
			printf("part1 --> %c\n", part1[i]);
		}
		printf("part1 --> %c\n", part1[i]);
		if (save[i] == '\0')
		{
			free(save);
			save = NULL;
		}
	}
	printf("3----%s\n", part1);
	j = 0;
	while ((byte = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		x = 0;
		//append_till_n(buffer, part2, '\n');
		//part2 = append_till_n2(buffer, '\n');
		while (buffer[x] && buffer[x] != '\n')
			part2[j++] = buffer[x++];
		if (buffer[x] == '\n')
		{
			y = 1;
			break;
		}
		else if (buffer[x] == EOF)
			break;
	}
	printf("4----%s\n", part1);
	if (!save)
		save = ft_strdup(buffer);
	else if (x != byte || x != '\0')
		save = ft_strjoin(save, buffer);
	*line = ft_strjoin(part1, part2);
	return (y);
	free(part1);
	part1 = NULL;
	free(part2);
	part2 = NULL;
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