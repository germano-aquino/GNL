#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
int		ft_read_from_fd(char **buff_add, int fd);

char	*ft_realloc(char *ptr, int *size);

char	*ft_get_line(char **buff_add, int fd);

char	*get_next_line(int fd);

#endif