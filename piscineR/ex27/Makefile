# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artderva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:01:35 by artderva          #+#    #+#              #
#    Updated: 2018/11/07 22:15:38 by artderva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_display.c

NAME = ft_display_file

all : $(NAME)

$(NAME) :
	$(CC) -o $(NAME) $(CFLAGS) $(SRC)

clean :
	rm -f ft_display.o

fclean : clean
	rm -f $(NAME)

re : fclean all
