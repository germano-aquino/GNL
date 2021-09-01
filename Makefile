# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 11:25:54 by grenato-          #+#    #+#              #
#    Updated: 2021/08/29 22:48:57 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Rules that must have in makefile
# $(NAME), all, clean, fclean and re.

# define the C compiler
CC = clang

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror -I $(H_SOURCE) -D BUFFER_SIZE=99

# name of the project
NAME = get_next_line.a

# .c bonus files
#B_SOURCE =	
# .c mandatory files
C_SOURCE =	get_next_line.c\
			get_next_line_utils.c\
			main.c

# .h file
H_SOURCE = get_next_line.h

# mandatory object files
OBJ = $(C_SOURCE:.c=.o)

# bonus object files
#B_OBJ = $(B_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(B_OBJ)
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

#bonus: $(OBJ) $(B_OBJ)
#	ar rcs $(NAME) $(OBJ) $(B_OBJ)
