#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

static void	ft_init_buff(char *buff, int fd)
{
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	if (read(fd, buff, BUFFER_SIZE) == 0)
	{
		free(buff);
	}
	buff[BUFFER_SIZE] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	int		line_length;
	int		end_of_line;

	if (buff == NULL)
		ft_init_buff(buff, fd);
	if (*buff == '\0')
		return (NULL);
	line_length = 0;
	end_of_line = 0;
	while (end_of_line != 1 && *buff != '\0')
	{
		line_length++;
		buff++;
		if (*buff == '\n')
			end_of_line = 1;
	}
	line = malloc(sizeof(char) * (line_length + 1));
	if (line == NULL)
		return (NULL);
	ft_cpyline(line, buff, line_length);
	return (line);
}
