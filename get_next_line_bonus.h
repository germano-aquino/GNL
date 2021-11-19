/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:53 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/19 15:32:49 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

typedef struct buffer{
	char	*head;
	char	*letter;
}				buffer;

int		ft_read_from_fd(buffer *buff_add, int fd);

char	*ft_realloc(char **ptr, int *size, int first_allocation);

char	*ft_get_line(buffer *buff_add, int fd);

char	*get_next_line(int fd);

#endif