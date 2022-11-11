/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:29:01 by hamaarou          #+#    #+#             */
/*   Updated: 2022/11/10 20:20:28 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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
