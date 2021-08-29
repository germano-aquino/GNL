#ifndef BUFFER_SIZE
# define BUFFER_SIZE -1
char	*get_next_line(int fd)
{
	char	*buff;
	int		ret;
	
	ret = read(fd, buff, BUFFER_SIZE);

}

#endif