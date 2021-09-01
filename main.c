#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int main()
{
	int		k = 0;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	return (0);
}