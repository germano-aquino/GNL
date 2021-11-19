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

	fd = open("./tester/files/empty", O_RDONLY);
	do
	{
		if (breakLoop)
		{
			free(line);
			line = NULL;
		}
		line = get_next_line(fd);
		printf("%s", line);
		breakLoop++;
	} while (line != NULL && breakLoop != 20);
	free(line);
	close(fd);
	return (0);
}