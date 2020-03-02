NAME		=	mysh

CC		=	gcc

RM		=	rm -f

COMPILEFLAGS	=	-W -Wall -Wextra -ansi -pedantic

INCLUDES	=	./includes/

LDFLAGS		=

CFLAGS		=	$(COMPILEFLAGS) -I$(INCLUDES)

SRCS		=	src/buitin.c		\
			src/echo.c		\
			src/env.c		\
			src/exit.c		\
			src/ft_cd2.c		\
			src/ft_cd.c		\
			src/ft_cd_core.c	\
			src/ft_env.c		\
			src/ft_expanstr.c	\
			src/ft_which.c		\
			src/main.c		\
			src/tools_cd.c		\
			src/unsetenv.c

OBJS		=	$(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
