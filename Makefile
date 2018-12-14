# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2018/12/14 14:55:10 by jmoussu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/main.c \
	  srcs/parsing.c \
	  srcs/utils.c \
	  srcs/valid_file.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GREEN_OK = "\033[0;32mDONE !\033[00m"

all:  $(NAME)

$(NAME): $(OBJ)
	@cd libft && make
	@gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -Isrcs/
	@echo fillit ${GREEN_OK}

onlyfillit:
	@gcc -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -Isrcs/
	@echo onlyfillit ${GREEN_OK}

clean:
	@rm -f $(OBJ)
	@cd libft && make clean
	@echo clean fillit ${GREEN_OK}

fclean: clean
	@rm -f $(NAME)
	@echo fclean fillit ${GREEN_OK}

mclean: all clean

cleanexe:
	@rm -f $(NAME)

re: fclean all
