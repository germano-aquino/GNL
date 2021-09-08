//file of libft function
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	char	*ret;

	ret = (char *) malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dest) + 1));
	if (ret == NULL)
		return (NULL);
	j = 0;
	while (dest[j] != '\0')
	{
		ret[j] = dest[j];
		j++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		ret[j] = src[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
