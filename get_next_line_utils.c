/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:20:53 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/02 13:14:09 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_size(int fd)
{
	int i;
	char b;

	i = 0;
	fd = open(FILE, O_RDONLY);
	while ((read(fd, &b, 1) > 0))
	{
		if (b == '\n' || b == '\0')
			break;
		i++;
	}
	close(fd);
	return (i);
}

int	ft_error(int fd)
{
	if (!(fd = open(FILE, O_RDONLY)))
		return (-1);
	close(fd);
	return (1);
}
