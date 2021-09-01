#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_cpyline(char *line, char *buff, int i_index, int index)
{
	int	i;

	i = 0;
	while (i < index - i_index)
	{
		line[i] = buff[i_index + i];
		i++;
	}
	if (line[i] == '\0')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;
	int		sz;
	static int	index;
	int			initial_index;

	if (index == -1)
		return (NULL);
	initial_index = index;
	if (index == 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		if (read(fd, buff, BUFFER_SIZE) == 0)
			return (NULL);
	}
	//printf("size return is: %d\n", sz);
	while (buff[index] != '\n' && buff[index] != '\0')
		index++;
	//printf("buff[index] is %c\n", buff[index]);
	line = malloc(sizeof(char) * (index - initial_index + 2));
	if (line == NULL)
		return (NULL);
	//printf("I'm here %d\n", index);
	//printf("%s", buff);
	ft_cpyline(line, buff, initial_index, index);
	if (buff[index] == '\0')
		{
			index = -2;
			free(buff);
		}
	index++;
	return (line);
}
