/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:18:47 by cgross            #+#    #+#             */
/*   Updated: 2022/11/07 18:30:58 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd)
{
	size_t	i;
	static char	*buff;
	char	*backup;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	read(fd, buff, BUFFER_SIZE);
	backup = buff;
	i = 0;
	while (backup[i] || backup[i] != '\n')
	{
		while (backup[i] != '\n')
			i++;
	}
	printf("get_line:	%s\n", backup);
	return (backup);
}




char	*get_next_line(int fd)
{
	size_t	i;
	size_t	j;
	static char	*buff;

	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	get_line(fd);
	//printf("str: 	:%s:", str);
	return (0);
}

int	main()
{
	int fd = open("txt.txt", O_RDONLY);

	get_line(fd);
//	printf("%s\n", get_next_line(fd));
//	printf("%d\n", fd);
}
