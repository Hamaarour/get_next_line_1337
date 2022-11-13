/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2022/11/13 13:23:06 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ss(int fd, char *buffer, char *tmp, char **string)
{
	int		bytes;

	bytes = 1;
	while (ft_strchr(tmp) == 0 && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes == -1)
			{
				free(*string);
				*string = NULL;
				free(tmp);
				tmp = NULL;
			}
			break ;
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(&tmp, buffer);
	}
	return (tmp);
}

char	*ft_read(int fd, char **string)
{
	char	*buffer;
	char	*tmp;

	tmp = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	tmp = ft_strjoin(string, buffer);
	tmp = ss(fd, buffer, tmp, string);
	free(buffer);
	if (tmp && tmp[0] == 0)
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}

char	*get_line_ss(char **string, char *str)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	buff = malloc((i + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (++j < i)
		buff[j] = str[j];
	buff[j] = '\0';
	if (str[i])
		*string = ft_substr(str, i, ft_strlen(str));
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*string[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read(fd, &string[fd]);
	if (!line)
		return (NULL);
	line = get_line_ss(&string[fd], line);
	return (line);
}
#include <stdio.h>
int main ()
{
	int fd1 = open("test1.txt",O_RDONLY, 0777);

	int fd2 = open("test2.txt",O_RDONLY, 0777);

	int fd3 = open("test3.txt",O_RDONLY, 0777);

	char *str = get_next_line(fd1);
	printf("%s",str);
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd1));
}
