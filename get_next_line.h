#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strcat(char *dest, char *src);

static void	ft_cpyline(char *line, char *buff, int len);

static int	ft_findEndOfLine(char **buff);

#endif