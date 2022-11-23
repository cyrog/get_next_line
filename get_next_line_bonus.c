/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:29:18 by cgross            #+#    #+#             */
/*   Updated: 2022/11/23 16:48:17 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *join)
{
	int		ret;
	char	*buffer;

	if (!join)
		join = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			free(join);
			return (0);
		}
		buffer[ret] = '\0';
		join = ft_strjoin(join, buffer);
		if (ft_strchr('\n', buffer))
			ret = 0;
	}
	free(buffer);
	return (join);
}

char	*gets_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	else
		line[i] = '\0';
	line[++i] = '\0';
	return (line);
}

char	*get_rest(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	rest = ft_calloc(sizeof(char), ft_strlen(line) - i + 1);
	if (!rest)
		return (0);
	i++;
	while (line[i])
	{
		rest[j] = line[i];
		i++;
		j++;
	}
	free(line);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = gets_line(buffer[fd]);
	buffer[fd] = get_rest(buffer[fd]);
	return (line);
}
