# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artderva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 18:05:08 by artderva          #+#    #+#              #
#    Updated: 2020/06/12 15:28:38 by artderva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes
SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_split.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_swap.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isspace.c \
	ft_strupcase.c \
	ft_strlowcase.c \
	ft_ulltoa_base.c \
	ft_lltoa.c \
	ft_sjoin.c \
	ft_atoll.c \
	ft_strjoin1.c \
	ft_strjoin2.c \
	get_next_line.c \
	ft_del_tab.c \
	ft_strcut.c \
	ft_stchr.c \
	printf/conv_csp.c	\
	printf/conv_di.c	\
	printf/conv_f.c	\
	printf/conv_negdi.c	\
	printf/conv_oux.c	\
	printf/datafs.c	\
	printf/dispatch.c	\
	printf/lenm.c	\
	printf/printf.c	\
	printf/things.c	\
	printf/things2.c \
	ft_lst_push_back.c

SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)

NAME = libft.a

all : $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "library compiled"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
