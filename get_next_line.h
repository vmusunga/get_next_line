/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:47:21 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/26 15:52:35 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//# define BUFFER_SIZE 40000

size_t	ft_strlen(const char *str);
void	ft_free(char **s1, char **s2, int a, int b);
int		ft_free_one(char **s1, int x);
int		ft_free_return(char **s1, char **s2, int x);
int		get_next_line(int fd, char **line);
int		line_saver(char *save, int x, char **line);
char	*save_trim(char *save, int x);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif