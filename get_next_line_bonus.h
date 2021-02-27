/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:47:21 by vmusunga          #+#    #+#             */
/*   Updated: 2021/02/27 14:38:13 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
void	ft_free(char **s1, char **s2, int a, int b);
int		ft_free_return(char **s1, char **s2, int x);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif