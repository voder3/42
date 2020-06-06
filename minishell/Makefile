NAME			= minishell
SRC			= src/main.c \
			src/ft_env.c \
			src/builtin.c \
			src/echo.c \
			src/exit.c \
			src/unsetenv.c \
			src/exec.c \
			src/tools_exec.c \
			src/ft_expanstr.c \
			src/exp_dollar.c \
			src/tools.c \
			src/cd/chdir_errors.c \
			src/cd/chdir_errors2.c \
			src/cd/ft_cd2.c \
			src/cd/ft_cd.c \
			src/cd/ft_cd_core.c \
			src/cd/tools_cd.c
INC			= includes/
CC			= clang
CFLAGS			= -I $(INC)
OBJ			= $(SRC:.c=.o)
LIB			= libft/libft.a

all: $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[minishell] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[minishell] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L libft -lft
clean:
	@/bin/rm -f $(OBJ)
	@printf "[minishell] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[minishell] Removed minishell binary!\n"
re: fclean all

.PHONY: all clean fclean re
