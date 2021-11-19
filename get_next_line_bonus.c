/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:45 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/19 15:39:56 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_read_from_fd(buffer *buff_add, int fd)
{
	int	sz;

	sz = read(fd, (*buff_add).head, BUFFER_SIZE);
	if (!sz || sz == -1)
		return (0);
	(*buff_add).head[sz] = '\0';
	(*buff_add).letter = (*buff_add).head;
	return (1);
}

char	*ft_realloc(char **ptr, int *size, int first_allocation)
{
	char	*new;
	int		index;

	*size += BUFFER_SIZE;
	new = (char *) malloc(sizeof(char) * *size);
	if (!new)
		return (NULL);
	index = 0;
	new[index] = '\0';
	if (!first_allocation)
	{
		while (index < *size - BUFFER_SIZE - 1)
		{
			new[index] = *(*ptr + index);
			index++;
		}
		free(*ptr);
		*ptr = NULL;
	}
	return (new);
}

char	*ft_get_line(buffer *buff_add, int fd)
{
	char	*line;
	int		line_size;
	int		index;
	int		line_not_end;

	line_size = 1;
	line = ft_realloc(&line, &line_size, 1);
	index = 0;
	line_not_end = 1;
	while (line_not_end)
	{
		if (*buff_add->letter == '\0' && !ft_read_from_fd(buff_add, fd))
			return (line);
		line[index] = *buff_add->letter;
		if (*buff_add->letter == '\n')
			line_not_end = 0;
		(*buff_add).letter++;
		index++;
		if (index % BUFFER_SIZE == 0)
			line = ft_realloc(&line, &line_size, 0);
		line[index] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static buffer	buff[MAX_FD];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	if ((buff[fd]).head == NULL)
	{
		(buff[fd]).head = (char *) malloc(sizeof(char) * ((BUFFER_SIZE + 1)));
		(buff[fd]).letter = (buff[fd]).head;
		if (!(buff[fd]).head || !ft_read_from_fd(&(buff[fd]), fd))
		{
			ft_free(&(buff[fd]).head);
			(buff[fd]).letter = NULL;
			return (NULL);
		}
	}
	line = ft_get_line(&(buff[fd]), fd);
	if (line[0] == '\0')
	{
		ft_free(&line);
		ft_free(&(buff[fd]).head);
		(buff[fd]).letter = NULL;
		return (NULL);
	}
	return (line);
}
