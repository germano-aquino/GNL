/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:53 by grenato-          #+#    #+#             */
/*   Updated: 2021/11/11 10:53:31 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_read_from_fd(char **buff_add, int fd);

char	*ft_realloc(char *ptr, int *size);

char	*ft_get_line(char **buff_add, int fd);

char	*get_next_line(int fd);

#endif