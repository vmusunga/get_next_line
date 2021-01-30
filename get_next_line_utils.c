/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:20:53 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/26 16:20:53 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	ft_line_size(int fd)
{
	int i;
	char b;

	i = 0;
	open(fd, O_RDONLY);
	while ((read(fd, &b, 1) > 0) && (b != '\n' || b != '\0'))
		i++;
	return (i);
}

int	ft_error(int fd)
{
	if (!(open(fd, O_RDONLY)))
		return (-1);
	if (!((read(fd, &b, 1) > 0) && (b != '\n' || b != '\0')))
		return (-2);
	return (1);
}
