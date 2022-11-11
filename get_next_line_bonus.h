/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:52:12 by hamaarou          #+#    #+#             */
/*   Updated: 2022/11/11 09:08:56 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char	*ft_strchr(char *str, int j);
char	*ft_strjoin(char **left_str, char *buff);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*get_line_ss(char **left_str, char *str);
char	*ss(int fd, char *buffer, int bytes, char *tmp);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
