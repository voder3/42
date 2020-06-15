NAME = minishell

SRC += cd/ft_cd.c 
SRC += cd/ft_cd_core.c
SRC += cd/ft_cd2.c
SRC += cd/chdir_errors.c
SRC += cd/chdir_errors2.c
SRC += cd/tools_cd.c
SRC += builtin.c 
SRC += echo.c
SRC += exec.c
SRC += exp_dollar.c
SRC += exit.c
SRC += ft_env.c
SRC += ft_expanstr.c
SRC += main.c
SRC += tools.c
SRC += tools_exec.c
SRC += env.c

OPATHS += $(OPATH)cd

INCLUDES += minishell.h

CC = clang
COMPILE = $(CC) -c
WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(IPATH) -I $(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

MKDIR = mkdir -p
CLEANUP = rm -rf

OPATH = objs/
SPATH = srcs/
IPATH = includes/
LPATH = libft/
LIPATH = libft/includes/
LIB = $(LPATH)libft.a

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SPATH),$(SRC))
OBJS = $(addprefix $(OPATH),$(OBJ))
INCS = $(addprefix $(IPATH),$(INCLUDES))

all : $(NAME)

$(NAME) : lib $(OPATHS) $(OBJS) Makefile
	@$(CC) -o $@ $(OBJS) $(LIB)

$(OBJS) : $(OPATH)%.o : $(SPATH)%.c $(INCS)
	@$(COMPILE) $(CFLAGS) $< -o $@

$(OPATHS) :
	@$(MKDIR) $@

lib :
	@$(MAKE) -C $(LPATH)

clean :
	@$(MAKE) -C $(LPATH) clean
	@$(CLEANUP) $(OPATH)

fclean : clean
	@$(MAKE) -C $(LPATH) fclean
	@$(CLEANUP) $(OPATH)
	@$(CLEANUP) $(NAME)

re : fclean all

.PHONY: all clean fclean
