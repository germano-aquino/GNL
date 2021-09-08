#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
#endif

static void	ft_cpyline(char *line, char *buff, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		line[i] = *(buff - len + i);
		i++;
	}
	line[i] = '\0';
}

static int	ft_findEndOfLine(char **buff)
{
	int	end_of_line;
	int	line_len;

	end_of_line = 0;
	line_len = 0;
	while (end_of_line != 1 && **buff != '\0')
	{
		if (**buff == '\n')
			end_of_line = 1;
		(*buff)++;
		line_len++;
	}
	return (line_len);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*rest_of_line;
	char		*new_line;
	int			line_length;

	if (buff == NULL)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buff[BUFFER_SIZE] = '\0';
		if (read(fd, buff, BUFFER_SIZE) == 0)
			free(buff);
	}
	if (*buff == '\0')
		return (NULL);
	line_length = ft_findEndOfLine(&buff);
	line = malloc(sizeof(char) * (line_length + 1));
	if (line == NULL)
		return (NULL);
	ft_cpyline(line, buff, line_length);
	if (*buff == '\0' && read(fd, buff, BUFFER_SIZE) != 0)
	{
		buff[BUFFER_SIZE] = '\0';
		printf("line before gnl: %s\n",line);
		rest_of_line = get_next_line(fd);
		printf("this is rest_line: %s\n",rest_of_line);
		if (rest_of_line == NULL)
			return (NULL);
		new_line = ft_strcat(line, rest_of_line);
		printf("this is line: %s\n",line);
		printf("this is new_line: %s\n",new_line);
		if (new_line == NULL)
			return (NULL);
		free(line);
		free(rest_of_line);
		return (new_line);
	}
	return (line);
}
