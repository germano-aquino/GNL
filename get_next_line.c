/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:45 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/13 12:34:47 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_from_fd(char **buff_add, int fd)
{
	int		sz;
	char	*buff;

	buff = *buff_add;
	sz = read(fd, buff, BUFFER_SIZE);
	if (!sz || sz == -1)
		return (0);
	buff[sz] = '\0';
	return (1);
}

char	*ft_realloc(char *ptr, int *size)
{
	char	*new;
	int		index;

	*size += BUFFER_SIZE;
	new = (char *) malloc(sizeof(char) * *size);
	if (!new)
		return (NULL);
	index = 0;
	while (ptr[index] != '\0')
	{
		new[index] = ptr[index];
		index++;
	}
	new[index] = '\0';
	free(ptr);
	ptr = NULL;
	return (new);
}

char	*ft_get_line(char **buff_add, int fd)
{
	char	*line;
	int		line_size;
	int		index;
	int		line_not_end;

	line_size = BUFFER_SIZE + 1;
	line = (char *) malloc(sizeof(char) * line_size);
	if (!line)
		return (NULL);
	index = 0;
	line_not_end = 1;
	while (line_not_end)
	{
		if (**buff_add == '\0' && !ft_read_from_fd(buff_add, fd))
			return (line);
		if (index && index % BUFFER_SIZE == 0)
			line = ft_realloc(line, &line_size);
		line[index] = **buff_add;
		if (**buff_add == '\n')
			line_not_end = 0;
		(*buff_add)++;
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	if (buff == NULL)
	{
		buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff || !ft_read_from_fd(&buff, fd))
			return (NULL);
	}
	line = ft_get_line(&buff, fd);
	if (!line[0])
		return (NULL);
	return (line);
}
