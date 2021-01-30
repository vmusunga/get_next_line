/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:37 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/26 16:21:37 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int i;
	int x;

	char *buffer;
	char *new;

	if (ft_error(fd) < 0)
		return (0);

	open(fd, O_RDONLY);

	if (!(new = malloc(sizeof(char) * ft_line_size(fd))))
		return (0);
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);

	i = 0;
	while (read(fd, &buffer, BUFFER_SIZE) > 0)
	{
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
		{
			new[i++] = buffer[x];
			x++;
		}
		if (buffer[x] == '\n')
			break;
	}

	new[i] = '\0';
	close(fd);
	return (new);
}