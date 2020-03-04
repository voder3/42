NAME		:= minishell

CC			:= gcc
CFLAGS		+= 
CFLAGS		+= -I includes -I libft/includes
LDFLAGS		+= -L libft/ -lft

LIBFT		:= libft/libft.a

FILES		:= buitin echo ft_cd ft_cd2 ft_cd_core ft_env
FILES		:= ft_expanstr ft_which main tools_cd unsetenv

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^ libft/libft.a -g
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
