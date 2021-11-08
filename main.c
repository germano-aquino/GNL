#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char	*line;
	int		breakLoop = 0;

	fd = open("./test.txt", O_RDONLY);
	do
	{
		line = get_next_line(fd);
		printf("%s", line);
		breakLoop++;
	} while (line != NULL && breakLoop != 20);
	free(line);
	close(fd);
}