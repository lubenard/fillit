# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2018/12/12 15:18:10 by jmoussu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/main.c \
	  srcs/parsing.c \
	  srcs/utils.c \
	  srcs/valid_file.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -Isrcs/

onlyfillit:
	gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -Isrcs/

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

mclean: all clean

cleanexe:
	rm -f $(NAME)

re: fclean all
