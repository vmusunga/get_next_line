/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:42 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/10 11:51:47 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define BUFFER_SIZE 50
# define FILE "file.txt"

int	ft_error(int fd);
int	ft_line_size(int fd);
int	get_next_line(int fd, char **line);
char *save_buffer(char *buffer);
void	clear_save(char *save);

#endif