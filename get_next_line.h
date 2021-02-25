/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:47:21 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/25 15:42:36 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

//# define BUFFER_SIZE 40000
//# define FILE "file.txt"

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	*save_trim(char *save, int x);
int free_error(char **s1, char **s2, int x, int a, int b);

#endif