NAME	=	libftprintf.a

LIB		=	libft

OBJ_DIR	=	./obj
SRC_DIR	=	./src

CC		= 	gcc

CFLAGS	= 	-Wall -Wextra -Werror

SRC		=	./conv_csp.c \
			./conv_di.c \
			./conv_f.c \
			./conv_negdi.c \
			./conv_oux.c \
			./datafs.c \
			./dispatch.c \
			./things.c \
			./things2.c \
			./printf.c \
			./lenm.c

OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all:	$(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
		@make -C $(LIB)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIB)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean 
