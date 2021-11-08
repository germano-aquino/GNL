#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 0
#endif
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	int		index;
	int		line_size;
	int		sz;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 255)
		return (NULL);
	if (buff == NULL)
	{
		buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		sz = read(fd, buff, BUFFER_SIZE);
		if (!sz || sz == -1)
			return (NULL);
		buff[sz] = '\0';
	}
	line_size = BUFFER_SIZE;
	line = (char *) malloc(sizeof(char) * (line_size + 1));
	index = 0;
	if (*buff == '\n')
		buff++;
	if (*buff == '\0')
	{
		sz = read(fd, buff, BUFFER_SIZE);
		buff[sz] = '\0';
	}
	line[index] = *buff;
	while (*buff != '\n')
	{
		buff++;
		index++;
		if (index % BUFFER_SIZE == 0)
		{
			line_size += BUFFER_SIZE;
			line = (char *) realloc(line, line_size + 1);
		}
		if (*buff == '\0')
		{
			sz = read(fd, buff, BUFFER_SIZE);
			if (!sz || sz == -1)
			{
				if (!line[0])
					return (NULL);
				break;
			}
			buff[sz] = '\0';
		}
		line[index] = *(buff);
	}
	index++;
	line[index] = '\0';
	return (line);
}
