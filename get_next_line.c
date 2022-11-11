/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:30:16 by hamaarou          #+#    #+#             */
/*   Updated: 2022/11/11 09:57:14 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ss(int fd, char *buffer, int bytes, char *tmp)
{
	while (!ft_strchr(tmp, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(&tmp, buffer);
	}
	return (tmp);
}

char	*ft_read(int fd, char **string)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	tmp = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	buffer[0] = 0;
	tmp = ft_strjoin(string, buffer);
	tmp = ss(fd, buffer, bytes, tmp);
	free(buffer);
	if (bytes == -1)
	{
		free(tmp);
		return (NULL);
	}
	if (!tmp[0])
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
	if (str[i] != '\0')
		*string = ft_substr(str, i, ft_strlen(str));
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read(fd, &string);
	if (!line)
		return (NULL);
	line = get_line_ss(&string, line);
	return (line);
}


// int	main(void)
// {
// 	char	*line;
// 	int		fd1;

// 	fd1 = open("tests/test2.txt", O_RDONLY, 0777);
// 	line = get_next_line(fd1);
// 	printf("%s", line);free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);free(line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	system("leaks a.out");
// 	return (0);
// }
