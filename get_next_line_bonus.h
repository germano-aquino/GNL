/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:53 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/21 22:49:45 by grenato-         ###   ########.fr       */
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

typedef struct s_buffer{
	char	*begin;
	char	*end;
}				t_buffer;

int		ft_read_from_fd(t_buffer *buff_add, int fd);

char	*ft_line_alloc(char **ptr, int *size, int first_allocation);

char	*ft_get_line(t_buffer *buff_add, int fd);

char	*get_next_line(int fd);

#endif